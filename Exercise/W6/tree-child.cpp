#include <memory>
#include <string>
#include <vector>
#include <iostream>

template <typename T>
class Tree{
private:
    class Node{
    public:
        Node(T v) : value_(std::move(v)){}
        Node():children_(NULL){}
        T value_;
        std::vector<std::unique_ptr<Tree>> children_;
    };
    std::unique_ptr<Node> root_;

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
        return *this;
    }

/**
 * Add a subtree to the top level of this tree, using move
 * semantics to "steal" the subtree's nodes.
 */
    Tree& addSubtree(Tree<T>&& subTree){
        root_->children_.push_back(std::move(subTree.root_));
        return this;
    }

    void visit_preorder(Node* node){
        if(!node) return;
        node = node->children_.begin();
        node = node->children_++;
        for(auto i = node->children_--.begin(); i != node->children_.end(); i++){
            visit_preorder(i);
        }
    }

    void visit_postorder(Node* node){
        if(!node) return;
        node = node->children_.begin();
        for(auto i = node->children_.begin(); i != node->children_.end(); i++){
            visit_postorder(i);
        }
        node = node->children_++;
    }

};
