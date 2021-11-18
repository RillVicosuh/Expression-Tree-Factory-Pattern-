#ifndef _FACTORY_HPP_
#define _FACTORY_HPP_

#include "base.hpp"
#include "op.hpp"
#include <cstring>

class Factory{
  private:
    Base* createExpression(Base* leftValue, Base* rightValue, char currOp){
      if(currOp == '+'){
        return new Add(leftValue, rightValue);
      }
      else if(currOp == '-'){
        return new Sub(leftValue, rightValue);
      }
      else if(currOp == '*'){
        return new Mult(leftValue, rightValue);
      }
      else if(currOp == '/'){
        if(rightValue->evaluate() == 0){
          cout << "Denominator cannot be 0" << endl;
          return nullptr;
        }
        return new Div(leftValue, rightValue);
      }
      else if(currOp == '^'){
        return new Pow(leftValue, rightValue);
      }
      else{
        return nullptr;
      }
    }
    
    bool validOp(char* currOp){
      int length = strlen(currOp)
      if(length == 1){
        if(currOp[0] != '+' && currOp[0] != '-' && currOp[0] != '/' && currOp[0] != '*'){
          return false;
        }
      }
      else if(length >= 2){
        return false; 
      }
      return true;
    } 
 
  public:
    Factory(){}
    

};
#endif //_FACTORY_HPP_
