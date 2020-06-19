#include <memory>
#include <string>
#include <vector>
#include <iostream>

template <typename T>
class Tree{
public:
    Tree(){}
    Tree(T value) : value_(value){}


/**
 * Set the value of the tree's root node.
 */
    Tree& setRoot(T value){
        std::unique_ptr<Tree> node = std::make_unique<Tree>(value);//Why we need have a <Tree> when we call make_unique()
        if (!root_) {
            root_ = std::move(node);
        }else{
            std::cout<<"This tree already have a root"<<"\n";
        }
        //how to return this lvalue ??
        return node;
    }

/**
 * Add a leaf node to the top level of this tree.
 */
    Tree& addChild(T value){
        std::unique_ptr<Tree> node = std::make_unique<Tree>(value);
        children_.push_back(std::move(node));
        return node;
    }

/**
 * Add a subtree to the top level of this tree, using move
 * semantics to "steal" the subtree's nodes.
 */
    Tree& addSubtree(Tree<T>&&){
        std::unique_ptr<Tree> node = std::make_unique<Tree>;
        children_.push_back(std::move(node));
        return node;
    }

private:

    T value_;
    std::vector<std::unique_ptr<Tree>> children_;
    std::unique_ptr<Tree> root_;
};

int main(){
    Tree<std::string> tree;
    tree.setRoot("Hello Word");

    tree.setRoot("Hello Earth");

}