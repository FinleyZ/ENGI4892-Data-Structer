#include <memory>
#include <string>
#include <vector>
#include <iostream>


template <typename T>
class SiblingTree{
public:

    SiblingTree(){
    }


/**
 * Set the value of the tree's root node.
 */
    SiblingTree& setRoot(T value){
        std::unique_ptr<Node> node = std::make_unique<Node>(value);
        if (!root_) {
            root_  = std::move(node);
        }else{
            root_->value_ = value;
            std::cout<<"This tree already have a root"<<"\n";
        }

        return *this;
    }

/**
 * Add a leaf node to the top level of this tree.
 */
    SiblingTree& addChild(T value){
        std::unique_ptr<Node> node = std::make_unique<Node>(value);
        root_->sibling_.push_back(std::move(node));
        return *this;
    }

/**
 * Add a subtree to the top level of this tree, using move
 * semantics to "steal" the subtree's nodes.
 */
    SiblingTree& addSubtree(SiblingTree<T>&& subTree){
        root_->children_ = std::move(subTree.root_);
        return this;
    }

private:
    class Node{
    public:
        Node(T v) : value_(std::move(v)){}
        T value_;
        std::vector<std::unique_ptr<SiblingTree>> sibling_;
        std::unique_ptr<SiblingTree> children_;
    };
    std::unique_ptr<Node> root_;
};


