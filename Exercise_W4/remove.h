#include <vector>
#include <list>
#include<iostream>
#include <memory>
using namespace std;

// a function that remove  numbers from list that are multiples of 10
template <typename T>
void RemoveMultOf10(T &list){
    //an iterator got through a list
    for ( auto  i = list.begin(); i != list.end(); i++   )//dont know why typename std::list<T>::iterator not work here
    {
        //if a numbers from list that are multiples of 10.
        if(*i % 10 == 0){
            std::cout<<*i<< " removed " <<"\n";
            i = list.erase(i);
        }
    }
    //print List
    std::cout << "The list elements are : ";
    for ( auto  i = list.begin(); i != list.end(); i++   )
    {
        std::cout<<*i<<" ";
    }
    std::cout<<"\n";

}


// a function that remove the same numbers from a vector
template <typename T>
void RemoveSameNumber(T &vector)
{
    //an iterator got through a list
    for ( auto  i = vector.begin(); i != vector.end(); i++)
    {
        //an iterator iterating one after i iterator until end of the vector
        for ( auto  j = i+1; j != vector.end(); i++){
            if(*i==*j){
                j = vector.erase(j);
            }
        }
    }
    //print vector
    std::cout << "The vector elements are : ";
    for(int k=0; k < vector.size(); k++)
        std::cout << vector.at(k) << ' ';
    std::cout<<"\n";
}

template <typename T>
int partition(T *a,T start,T end)
{
    T pivot=a[end];
    //P-index indicates the pivot value index

    T P_index=start;
    int i,t; //t is temporary variable

    //Here we will check if array value is
    //less than pivot
    //then we will place it at left side

    for(i=start;i<end;i++)
    {
        if(a[i]<=pivot)
        {
            t=a[i];
            a[i]=a[P_index];
            a[P_index]=t;
            P_index++;
        }
    }
    //swapping value of
    //pivot and P-index
    t=a[end];
    a[end]=a[P_index];
    a[P_index]=t;

    //at last returning the pivot value index
    return P_index;
}

template<typename T>
void Quicksort(T *a,T start,T end)
{
    if(start<end)
    {
        T P_index=partition(a,start,end);
        Quicksort(a,start,P_index-1);
        Quicksort(a,P_index+1,end);
    }
}

template<typename T>
class LinkedList {
public:
            LinkedList() : tail_(nullptr){

            }

            void append(T x){
                auto node = std::make_unique<Node>(x);//not sure whats make_unique<Node> meaning here
                    if (this->tail_){
                        tail_->next_ = std::move(node);
                        tail_ = tail_-> next_.get();

                    }else{
                        head_ = std::move(node);
                        tail_ = head_.get();
                    }
            }


private:
            class Node{
            public:
                Node(T value) : value_(value){

                }

                T value_;
                std::unique_ptr<Node> next_;
                Node *prev_;
            };

            std::unique_ptr<Node> head_;
            Node *tail_;

        };