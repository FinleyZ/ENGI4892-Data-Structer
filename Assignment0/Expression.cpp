//I know there is so many things is wrong in this code...

#include <iostream>
#include <cmath>
#include "Expression.h"
#include <memory>	// std::unique_ptr
#include <mach_debug/zone_info.h>
using namespace std;
using namespace calc;


class LiteralExpression: public Expression{
public:
    double oneNumber;
    LiteralExpression (double a);
    double gatValue(){ return val; }
    virtual double evaluate() const override;

    protected:
    double val;

};

class Calculation: public BinaryExpression{
    double result;
};


ExpPtr Expression::Literal(double a){
    Expression *address=new LiteralExpression(a); // pointer to an LiteralExpression object
    ExpPtr p(address); // take that as a pointer to ExpPtr
    static_cast<LiteralExpression*>(address)->oneNumber = a;
    return p;  // return ExpPtr
}

// Literal class constructor
LiteralExpression::LiteralExpression(double a) {
    val = a;
}

// implement virtual method
double LiteralExpression::evaluate() const{
    return val;
}


// override virtual method from parent
double Litera::evaluate() const{
    return val;
}

// override virtual method from parent
double Calculation::evaluate() const {
    return result;
}

// BinaryOperation class constructor
BinaryExpression::BinaryExpression(ExpPtr lhs, ExpPtr rhs) {

    lhs_= lhs -> oneNumber;
    rhs_= rhs -> onenumber;
}



//Add constructor
ExpPtr BinaryExpression::Add(ExpPtr lhs, ExpPtr rhs){
    BinaryExpression *address=new BinaryExpression(std::move(lhs), std::move(rhs));
    address->result=(address->lhs_)+(address->rhs_);
    double temp=address->result;
    ExpPtr p (address);
    p->oneNumber=temp;
    return p;
}

// Subtract constructor
ExpPtr BinaryExpression::Subtract(ExpPtr lhs, ExpPtr rhs){
    BinaryExpression *address=new BinaryExpression(std::move(lhs), std::move(rhs));
    address->result=(address->lhs_)-(address->rhs_);
    double temp=address->result;
    ExpPtr p (address);
    p->oneNumber=temp;
    return p;
}

// Multiply constructor
ExpPtr BinaryExpression::Multiply(ExpPtr lhs, ExpPtr rhs){
    BinaryExpression *address=new BinaryExpression(std::move(lhs), std::move(rhs));
    address->result=(address->lhs-)*(address->rhs_);
    double temp=address->result;
    ExpPtr p (address);
    p->oneNumber=temp;
    return p;
}

// Divide constructor
ExpPtr BinaryExpression::Divide(ExpPtr lhs, ExpPtr rhs){
    BinaryExpression *address=new BinaryExpression(std::move(lhs), std::move(rhs));
    address->result=(address->lhs_)/(address->rhs_);
    double temp=address->result;
    ExpPtr p (address);
    p->oneNumber=temp;
    return p;
}




