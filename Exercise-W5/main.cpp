#include <iostream>
#include <vector>
#include <stdio.h>
#include <string.h>
using namespace std;



//initialize an int variable in stack.
void recursive(int n){
    if (n == 0)
        return;
    int a;
    printf("%p\n", &a);
    recursive(n - 1);//recursion of recursive()
}

int stringOperation(string Operator,int operand1,int operand2 ){
    if (Operator == "-"){
        return (operand1 - operand2);
    }else if (Operator == "/"){
        return (operand1/operand2);
    }else if (Operator == "*"){
        return (operand1*operand2);
    }else if (Operator == "+"){
        return (operand1+operand2);
    }else {
        return operand1;}
}

//Unfortunately this code have a lot of error, I dont not have enough time to fix it.
int RPN_Expression(vector<string> vector){
    int hold1 = 0;
    int hold2 = 0;

//    for (auto it1  = vector.begin() ; it1 != vector.end(); ++it1) {
//        if(*it1 != "1"
//            && *it1 != "2"
//            && *it1 != "3"
//            && *it1 != "4"
//            && *it1 != "5"
//            && *it1 != "6"
//            && *it1 != "7"
//            && *it1 != "8"
//            && *it1 != "9"
//            && *it1 != "0")
//        {
//            std::cout<<*it1<<"is an invalid input"<<"\n";
//        }else{
//            hold1 = stoi(*it1);
//            hold2 = stoi(*(it1));
//            std::cout<<hold1<<"\n";
//
//        }

        for (auto it = vector.begin() ; it != vector.end(); ++it) {
            if(*it == "1"
               && *it == "2"
               && *it == "3"
               && *it == "4"
               && *it == "5"
               && *it == "6"
               && *it == "7"
               && *it == "8"
               && *it == "9"
               && *it == "0")
            {
                hold2 = hold1;
                hold1 = stoi(*it);

            }else{
                hold1 = stringOperation(*it,hold1,hold2 );
                std::cout<<hold1<<"\n";
            }

        }


        return hold1;
}


class Queue{
private:
    std::string queue;
    string last;
    int size = 0;

public:
    void enqueue(){
        int number;
        std::cout<<"Enter your enqueue: ";
        std::cin>>number;
        std::cout<<'\n';
        this->last = number;
        queue = queue + std::to_string(number);
        this-> size++;
        std::cout<<"your enqueue: "<<this->queue;

    }

    void dequeue(){
        int lastSize = this->last.size();
        this->queue = queue.erase(lastSize);
        this->size--;
        std::cout<<"your enqueue: "<<this->queue;
    }

    int Size(){
        return this->size;

    }



};

int main() {
    //Demonstrate the stack
    //recursive(5);

    std::vector<string> expression = {"1","2","+","3","*"};

    std::cout<<RPN_Expression(expression)<<"\n";

}