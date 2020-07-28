/*
 * Copyright 2018 Jonathan Anderson
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

template<typename T, typename Comparator = std::less<T>>
class BST
{
public:
    BST(){std::cout<<"\n";}
	//! Does this tree contain the given value?
	bool contains(const T &value)
	{
		return (not empty() and root_->contains(value));
	}

	size_t maxDepth() const
	{
		if (empty())
		{
			return 0;
		}

		return root_->maxDepth();
	}

	//! Is this tree empty?
	bool empty() const
	{
		return (not root_);
	}

	//! Insert a new value into the appropriate place in the tree.
	void insert(T value)
	{
		insert(std::move(value), root_);
	}

	/**
	 * Find the minimum value in the tree.
	 *
	 * @pre   tree is not empty
	 */
	const T& min() const
	{
		assert(root_);
		return root_->min().value();
	}

	/**
	 * Find the minimum value in the tree.
	 *
	 * @pre   tree is not empty
	 */
	const T& max() const
	{
		assert(root_);
		return root_->max().value();
	}

    const BST& print(std::ostream &out) const{
	    if(root_){
            root_->print(out);
	    }
        return *this;
    }
     /**
     * Output this tree in a GraphViz DOT representation as a
     * directed graph ("digraph").
     *
     * Calls to this method will cause an entire graph (starting
     * with "digraph G {") to be output to the given std::ostream.
     *
     * @param   o    the output stream to write to
     */
    void printDot(std::ostream &out) const{
         if(root_){
             root_->printDot(out);
         }
         out<<"\n";

         if (root_->left_){
             root_->left_->printDot(out);
         }
         out<<"\n";

         if (root_->right_){
             root_->right_->printDot(out);
         }
         out<<"\n";

    }

	/**
	 * Remove a value (if it exists) from the tree.
	 *
	 * @returns   whether or not anything was found to remove
	 */
	bool remove(const T &&value)
	{
		return remove(value, root_);
	}

    //A method to rotate a subtree
    BST rotate(BST *root_) {
        BST *temp;
        temp = root_->right_;
        root_->right = temp->left_;
        temp->l = root_;
        std::cout << "Right-Right Rotation";
        return temp;
    }

private:
	struct Node
	{
		// Did you know that structs can have methods too?
		Node(T &&value)
			: element_(value), count_(1)
		{
		}

		const T& value() const { return element_; }
        const T& count() const { return count_; }

		bool contains(const T&) const;
		Node& min(){
		    if (left_){
                return left_->min();
		    }

		    return *this;
		}

		Node& max(){
            if (right_){
                return right_->min();
            }

            return *this;
        }

        const Node& print(std::ostream &out) const{
		    if (left_){
		        left_->print(out);
		    }
		    out << value() << " x " << count() << std::endl;

            if (right_){
                right_->print(out);
            }
            return *this;
		}

		T takeMin();
		size_t maxDepth() const;

		T element_;
		size_t count_;
		std::unique_ptr<Node> left_;
		std::unique_ptr<Node> right_;


        /**
         * Output information about this node in GraphViz DOT format.
         *
         * This will output information about this node
         * (with no graph-level decorations such as "digraph G {")
         * and recursively descend to its children.
         */
        void printDot(std::ostream &out) const{
            out<< value() <<"[ label = \"count " << count_<< ", value " << value()<<"\""<<" ];"<<"\n";

            if (left_){
                out<< value()<<" -> "<< left_->value() <<"[ label = \"L\" ];"<<"\n";
            }
            if (right_){
                out<< value()<<" -> "<< right_->value() <<"[ label = \"R\" ];"<<"\n";
            }
        }
	};

	/**
	 * Internal implementation of recursive insert.
	 *
	 * @param   value      the value to insert
	 * @param   node       the root of the (sub-)tree being inserted into;
	 *                     may be null if the (sub-)tree is empty
	 */
	void insert(T &&value, std::unique_ptr<Node> &node){
	    if (not node){
	        node = std::make_unique<Node>(std::move(value));

	    } else if (compare_(value, node->value())){
	        insert(std::move(value), node->left_);

	    } else if (compare_(node->value(), value)){
            insert(std::move(value), node->right_);

	    } else {
	        node->count_++;
        }
	}

	/**
	 * Internal implementation of recursive removal.
	 *
	 * @param   value      the value to remove
	 * @param   node       the root of the (sub-)tree being inserted into;
	 *                     may be null if the (sub-)tree is empty
	 */
	bool remove(const T &value, std::unique_ptr<Node> &node);

	Comparator compare_;
	std::unique_ptr<Node> root_;
};


// Unfortunately im having trouble with implementing subclass of the BinarySearchTree class,
// it always gives me a error of "Expected class name" while I try to creat a sub Class
