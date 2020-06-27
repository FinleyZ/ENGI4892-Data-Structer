#include <memory>
#include <string>
#include <vector>
#include <iostream>

template <typename T>
class Tree{
public:

    Tree(){
    }


/**
 * Set the value of the tree's root node.
 */
    Tree& setRoot(T value){
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
    Tree& addChild(T value){
        std::unique_ptr<Node> node = std::make_unique<Node>(value);
        root_->children_.push_back(std::move(node));

//        node->children_.push_back(std::move(node));
        return *this;
    }

/**
 * Add a subtree to the top level of this tree, using move
 * semantics to "steal" the subtree's nodes.
 */
    Tree& addSubtree(Tree<T>&& subTree){
        root_->children_.push_back(std::move(subTree.root_));
        return this;

//        std::unique_ptr<Tree> node = std::make_unique<Tree>;
//        children_.push_back(std::move(node));
//        return node;
    }

private:
    class Node{
    public:
        Node(T v) : value_(std::move(v)){}
        T value_;
        std::vector<std::unique_ptr<Tree>> children_;
    };
    std::unique_ptr<Node> root_;
};

int main(){
    Tree<std::string> tree;
    tree.setRoot("Hello Word");

    tree.setRoot("Hello Earth");
}