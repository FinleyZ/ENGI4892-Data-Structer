#include <memory>
#include <string>
#include <vector>

template <typename T>
class Tree {
private:

    class Node{
    public:
        Node(T v):value_ (std::move(v)){}

        void addChild(std::unique_ptr<Node> child){
            children_.push_back(std::move(child));
        }

    private:
        T value_;
        std::vector<std::unique_ptr<Node>> children_;
    };

    std::unique_ptr<Node> root_;

public:
    Tree(){}

    void addNode(T v){
        std::unique_ptr<Node> node = std::make_unique<Node>(v);
        if(! root_){
            root_ = std::move(node);
        }else{
            root_-> addChild(std::move(node));
        }
    }

};


//int main() {
//    Tree<std::string> tree;
//    tree.addNode("1");
//    tree.addNode("hi ");
//
//}
