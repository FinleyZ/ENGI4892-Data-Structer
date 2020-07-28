/*
 * Copyright 2018-2019 Jonathan Anderson
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <cassert>
#include <cstddef>      // for definition of size_t
#include <functional>   // std::function
#include <memory>       // std::unique_ptr
#include <stack>
#include <iostream>

template<typename T, typename Comparator = std::less<T>>
class BinarySearchTree
{
public:
    enum class Traversal
    {
        PreOrder,
        InOrder,
        PostOrder,
    };

    //! Insert a new value into the appropriate place in the tree.
    void insert(T value)
    {
        insert(std::move(value), root_);
    }

    void dot(std::ostream &o) const
    {
        o << "digraph {\n";

        if (root_)
        {
            root_->dot(o);
        }

        o << "}\n";
    }

private:
    struct Node;

public:
    /**
     * An iterator that can traverse the BST in some order.
     *
     * The iterator contains a "current" node, a stack of parent nodes and
     * a Traversal value to remind it which strategy it's following.
     */
    class Iterator
    {
    public:
        /**
         * Move to the next node in the tree that should be accessed.
         *
         * This operator method just calls private methods to try and
         * keep the logic of the various traversal mechanisms clear.
         */
        Iterator operator ++ (int)
        {
            Iterator tmp(*this);

            // if stack is empty, return immediately
            if (stack_.empty())
            {
                node_ = nullptr;
                return tmp;
            }

            switch (order_)
            {
                // when traverse in preorder, pop top node as current node
                // and push right child to stack first,
                // push left child to stack secondly
                case Traversal::PreOrder:
                {
                    node_ = popGetStack();
                    if (node_->right_)
                        stack_.push(node_->right_.get());
                    if (node_->left_)
                        stack_.push(node_->left_.get());

                    break;
                }
                    // when traverse in inorder, pop top node as current node
                    // and push right child to stack first
                    // then push right child's left child to stack recursively
                case Traversal::InOrder:
                {
                    node_ = popGetStack();
                    if (node_->right_)
                    {
                        auto tmp = node_->right_.get();
                        while (tmp)
                        {
                            stack_.push(tmp);
                            tmp = tmp->left_.get();
                        }
                    }

                    break;
                }
                    // when traverse in postorder, if current node is top node's left child,
                    // traverse top node's right child at first,
                    // push top node's right child to stack first,
                    // then push top node's right child's left child to stack recursively.
                    // pop top node as current node
                case Traversal::PostOrder:
                {
                    if (stack_.top()->left_.get() == node_)
                    {
                        auto tmp = stack_.top()->right_.get();
                        while (tmp)
                        {
                            stack_.push(tmp);
                            if (tmp->left_)
                                tmp = tmp->left_.get();
                            else if (tmp->right_)
                                tmp = tmp->right_.get();
                            else
                                tmp = nullptr;
                        }

                    }
                    node_ = popGetStack();

                    break;
                }
                default:
                {
                    // make no sense to here!
                    assert(0);
                    break;
                }
            }

            return tmp;
        }

        //! Dereference the iterator at its current position
        const T& operator * ()
        {
            return node_->element_;
        }

        //! Is this iterator *not* the same as another?
        bool operator != (const Iterator &other)
        {
            return node_ != other.node_;
        }

        // add whatever else you need here
        Iterator(Node* node, Traversal order = Traversal::InOrder)
                : order_(order)
        {
            // if node is null, return immediately
            if (node == nullptr)
            {
                node_ = nullptr;
                return;
            }

            switch (order_)
            {
                // when iterate in preorder, first visit current node,
                // then push right child to stack first,
                // push left child to stack secondly
                case Traversal::PreOrder:
                {
                    node_ = node;
                    if (node_->right_)
                        stack_.push(node_->right_.get());
                    if (node_->left_)
                        stack_.push(node_->left_.get());
                    break;
                }
                    // when iterate in inorder, first push current node to stack
                    // then push left child to stack recursively
                    // pop first node as current iterator's node from stack
                case Traversal::InOrder:
                {
                    while (node)
                    {
                        stack_.push(node);
                        node = node->left_.get();
                    }
                    node_ = popGetStack();
                    break;
                }
                    // when iterate in postorder, first push current node to stack
                    // then push left child to stack recursively
                    // pop first node as current iterator's node from stack
                case Traversal::PostOrder:
                {
                    while (node)
                    {
                        stack_.push(node);
                        if (node->left_)
                            node = node->left_.get();
                        else if (node->right_)
                            node = node->right_.get();
                        else
                            node = nullptr;
                    }
                    node_ = popGetStack();
                    break;
                }
                default:
                {
                    // make no sense to here!
                    assert(0);
                    break;
                }
            }
        }

        // get top node and pop it from stack
        Node* popGetStack()
        {
            if (stack_.empty())
                return nullptr;
            auto tmp = stack_.top();
            stack_.pop();
            return tmp;
        }

        // null as default
        Node* node_ = nullptr;
        // inorder as default
        Traversal order_ = Traversal::InOrder;
        // a stack help iterate tree
        std::stack<Node*> stack_;
    };

    Iterator begin(Traversal order)
    {
        return Iterator(root_.get(), order);
    }

    Iterator end()
    {
        return Iterator(nullptr);
    }

private:
    struct Node
    {
        Node(T value) : element_(std::move(value))
        {
        }

        void dot(std::ostream &o) const
        {
            // NOTE: this is slightly more complicated than strictly
            //       necessary (using addresses as names, etc.), but
            //       it will produce valid Dot output even when the
            //       node values are things like money (e.g., $17)

            o
                    << "  \"" << this << "\""
                    << " [ label = \"" << element_ << "\" ];\n";

            if (left_)
            {
                o
                        << "  \"" << this << "\""
                        << " -> "
                        << "\"" << left_.get() << "\""
                        << " [ label = \"L\" ]\n";

                left_->dot(o);
            }

            if (right_)
            {
                o
                        << "  \"" << this << "\""
                        << " -> "
                        << "\"" << right_.get() << "\""
                        << " [ label = \"R\" ]\n";

                right_->dot(o);
            }
        }

        T element_;
        std::unique_ptr<Node> left_;
        std::unique_ptr<Node> right_;
    };

    /**
     * Internal implementation of recursive insert.
     *
     * @param   value      the value to insert
     * @param   node       the root of the (sub-)tree being inserted into;
     *                     may be null if the (sub-)tree is empty
     */
    void insert(T &&value, std::unique_ptr<Node> &node)
    {
        if (not node)
        {
            node = std::make_unique<Node>(std::move(value));
        }
        else if (compare_(value, node->element_))
        {
            insert(std::move(value), node->left_);
        }
        else if (compare_(node->element_, value))
        {
            insert(std::move(value), node->right_);
        }
        else
        {
            // assuming no duplicates
        }
    }

    Comparator compare_;
    std::unique_ptr<Node> root_;
};
