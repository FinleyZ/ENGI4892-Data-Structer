#include <iostream>
#include <vector>
using namespace std;



//initialize an int variable in stack.
void recursive(int n){
    if (n == 0)
        return;
    int a;
    printf("%p\n", &a);
    recursive(n - 1);//recursion of recursive()
}

int RPN_Expression(vector<char> vector){
    int hold = 0;
    for (auto it  = vector.begin() ; it != vector.end(); ++it) {
        std::cout<< *it <<"\n";

    }
    std::cout<<"hi";
    return 0;
}

int main() {
    //Demonstrate the stack
    //recursive(5);

    std::vector<char> expression = {'1','2','+','3','*'};

    RPN_Expression(expression);



//    for (auto i = expression.begin() ; i != expression.end(); ++i) {
//        std::cout<< *i <<"\n";
//
//    }



}