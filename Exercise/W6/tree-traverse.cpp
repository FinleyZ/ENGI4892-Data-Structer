#include <memory>
#include <iostream>
#include "tree-sibling.cpp"

template<typename T>
void visit(const T &value)
{
    static size_t i = 0;
    std::cout << "Node " << i++ << ": " << value << "\n";
}

int main(){


}
