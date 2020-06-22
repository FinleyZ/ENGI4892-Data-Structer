#include <iostream>
#include "List.h"

template <typename T>
void printList(List<T> a){

    for (typename List<T>:: iterator i = a.begin(); i != a.end() ; ++i) {
        std::cout<<*i<<" ";
    }
    std::cout<<"\n";
};


int main() {
    List<double> a;
    a.push_back(1.1);
    a.push_back(2.2);

    std::cout<<"insert at beginning: ";
    a.insert(a.begin(),3.3);
    printList(a);
    a.erase(a.begin());


    std::cout<<"insert at end: ";
    a.insert(a.end(),3.3);
    printList(a);
    a.erase(++++a.begin());

    std::cout<<"insert at middle: ";
    a.insert(++a.begin(),3.3);
    printList(a);

}
