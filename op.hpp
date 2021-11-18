#ifndef __OP_HPP__
#define __OP_HPP__

#include "base.hpp"
#include <stdexcept>
#include <limits>
#include <cmath>

#include <stdlib.h>
#include <time.h>
using namespace std;

class Op : public Base {
   private:
	double value;
	Base* leftChild;
	Base* rightChild; 

   public:
        Op(double value) : Base() {
          this->value = value;
        }
        virtual double evaluate() {
          return value;
        }
        virtual std::string stringify() {
          return to_string(value);
        }
        double getValue(){
          return this->value;
        }
        void setValue(double value){
          this->value = value;
        }
};

class Add : public Base {
    private:
	Base* left;
	Base* right;
    public:
	Add(Base* le, Base* ri) : Base()	{
	  left = le;
	  right = ri;
	}
	double evaluate() {
	  return left->evaluate() + right->evaluate();
	}
	std::string stringify() {
	  return "(" + left->stringify() + "+" + right->stringify() + ")"; 
  }
};

class Rand : public Base {
    private:
	double value;
    public:
	Rand() :	Base()	{
	   srand(time(0));
	   value = rand() %100;
	}
	 double evaluate() {
	   return value;
	}
	std::string stringify() {
	   return std::to_string(value);
	}

};

class Sub : public Base {
    private:
        Base* left;
        Base* right;
    public:
        Sub(Base* le, Base* ri) : Base() {
            left=le;
            right=ri;
        }
        double evaluate() {
            return left->evaluate() - right->evaluate();
        }
        std::string stringify() {
            return "(" + left->stringify() + "-" + right->stringify() + ")";
        }
};

class Mult: public Base{
   private:
	Base *leftChild, *rightChild;
   public :
	Mult(Base* left, Base* right): Base(){
	  if(left == nullptr || right == nullptr){
	    throw std::invalid_argument("Null argument passed into Mult class");           
	  }
	  leftChild = left;
          rightChild = right;
	}
	double evaluate(){
	  return leftChild->evaluate()*rightChild->evaluate();
	}
 	std::string stringify(){
	  return '(' +leftChild->stringify() + "*" + rightChild->stringify() + ')';
	}
};

class Div : public Base {
    private:
        Base *leftChild, *rightChild;
    public:
        Div(Base* left, Base* right) : Base() {
            if(left == nullptr || right == nullptr) {
              throw std::invalid_argument("Null argument passed into Div class.");
	    }
            leftChild = left; 
            rightChild = right;
            if(fabs(rightChild->evaluate()) < std::numeric_limits<double>::epsilon()){
		        throw std::invalid_argument("Divide by zero.");
	        }
        }

        double evaluate() {
            return leftChild->evaluate() / rightChild->evaluate();
        }

        std::string stringify() {
            return '(' + leftChild->stringify() + "/" + rightChild->stringify() + ')';
        }
};

class Pow: public Base{
  private: 
	Base *leftChild, *rightChild;
  public:
	Pow(Base* left, Base* right): Base(){
          if(left == nullptr || right == nullptr){
	    throw std::invalid_argument("Null argument passed into Pow class.");
          }
          if(left->evaluate() < 0 && !(right->evaluate() == floor(right->evaluate()))){
	    throw std::invalid_argument("An undefined or imaginary number");
	  }
          leftChild = left;
          rightChild = right;
	}
  	double evaluate(){
          return pow(leftChild->evaluate(), rightChild->evaluate());
	}
   	std:: string stringify(){
	  return '(' + leftChild->stringify() + "**" + rightChild->stringify() + ')';
	}
};

#endif //__OP_HPP__
