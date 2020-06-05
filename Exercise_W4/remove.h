#include <vector>
#include <list>
#include<iostream>
using namespace std;



template <typename T>

void listRemove(T list){
    for ( typename std::list<T>::iterator i : list){
        std::cout<<i<<" ";

    }

}