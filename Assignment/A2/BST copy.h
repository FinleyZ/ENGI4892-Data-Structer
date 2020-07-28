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
#include <iostream>
#include <stack>

template<typename T, typename Comparator = std::less<T>>

class BinarySearchTree
{
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

//        //added by myself not, sure if this right
//        Node* preOrder(){
//            Node* temp = preOrder();
//            if (left_){
//                left_ -> preOrder();
//            }
//            if (right_){
//                right_->preOrder();
//            }
//            return *this;
//        }

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
        Iterator operator ++ (int){
            switch (Traversal_){
                case Traversal::InOrder:
                    temp_ = data_;
                    if(!nodeStack.empty() || temp_ != nullptr){
                        inOrder();
                    }

                    break;

                case Traversal::PostOrder:
                    postOrder();
                    data_ = outStack.top();
                    outStack.pop();
                    break;

                case Traversal::PreOrder:
                    if (not data_){
                        return;
                    }
                    nodeStack.push(data_);
                    if (!nodeStack.empty()){
                    data_ = preOrder();
                    }

                    break;
            }

            return *data_;
        }

        //! Dereference the iterator at its current position
        const T& operator * (){
            return data_->element_;
        }

        //! Is this iterator *not* the same as another?
        bool operator != (const Iterator &other){
            return this->data_->element_ = other.data_->element_;
        }

        // add whatever else you need here

        Iterator(Traversal type, Node *other){
            Traversal_ = type;
            data_ = other;
        }

    private:
        Iterator preOrder(){
            if (not data_){
                return;
            }
            nodeStack.push(data_);

            Node* temp = nodeStack.top();
            nodeStack.pop();

            if (temp -> right_){
                nodeStack.push(data_ -> right_);}

            if (temp -> left_){
                nodeStack.push(data_-> left_);
            }

            return *temp;
        }

        void postOrder(){
            nodeStack.push(data_);

            // run till stack is not empty
            while (!nodeStack.empty())
            {
                //pop a node from the stack and push the data to output stack
                Node *temp = nodeStack.top();
                nodeStack.pop();

                outStack.push(temp->data);

                // push left and right child of popped node to the stack
                if (temp->left)
                    nodeStack.push(temp->left);

                if (temp->right)
                    nodeStack.push(temp->right);
            }
        }

        Iterator inOrder(){
            {
                // if current node is null and stack is also empty, we're done
                while (!nodeStack.empty() || temp_ != nullptr)
                {
                    // if current node is not null, push it to the stack (defer it)
                    // and move to its left child
                    if (temp_ != nullptr)
                    {
                        nodeStack.push(temp_);
                        temp_ = temp_->left;
                    }
                    else
                    {
                        // else if current node is null, we pop an element from stack,
                        // print it and finally set current node to its right child
                        temp_ = nodeStack.top();
                        nodeStack.pop();
                        data_ = temp_;
                        temp_ = temp_->right;
                    }
                    return *data_;
                }
            }
        }
        /**
         * Returns an iterator that can be used to traverse the tree in the given order.
         *
         * This iterator should visit every node in the tree exactly once, after which
         * it should test equal to the iterator returned from `end()`.
         */
        Iterator begin(Traversal order){
            Iterator it = new Iterator(order,root_);
            return it;
        }

        /**
         * The end of a tree traversal.
         *
         * The iterator returned by this method should be usable as the end-of-iteration
         * marker for any iterator on this tree, whether it was traversing the tree in
         * pre-, in- or post-order.
         */
        Iterator end(){
            switch(Traversal_){
                case Traversal::InOrder:
                    return Iterator(Traversal::InOrder,root_);

                case Traversal::PostOrder:
                    return Iterator(Traversal::PostOrder,root_);
                    break;
                case Traversal::PreOrder:
                    break;

            }
        }

        Traversal Traversal_;
        Node *data_;
        Node *temp_;
        std::stack<Node*> nodeStack;
        std::stack<Node*> outStack;
    };

};