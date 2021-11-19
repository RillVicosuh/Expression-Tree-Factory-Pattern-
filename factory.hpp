#ifndef _FACTORY_HPP_
#define _FACTORY_HPP_

#include "base.hpp"
#include "op.hpp"
#include <cstring>
#include <iostream>
using namespace std;

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
      int length = strlen(currOp);
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
    
    Base* parse(char** expression, int length){
      Base* leftValue = nullptr;
      Base* rightValue = nullptr;
      char currOp;
      bool endingOp = false;
      for (int i = 1; i < length; i++){
        char * ptrOp;
        int convValue = (int) strtol(expression[i], &ptrOp, 10);

        if(ptrOp != expression[i]){
          if((*ptrOp) && (*ptrOp <= '0' || *ptrOp >= '9')){
            return nullptr;
          }
          if(!leftValue){
            if(rightValue){
              return nullptr;
            }
            leftValue = new Op(convValue);
            endingOp = false;
          }
          else{
            rightValue = new Op(convValue);
            leftValue = createExpression(leftValue, rightValue, currOp);
            currOp = NULL;
            endingOp = false;
          }    
        }
        else if(!validOp(expression[i])){
          return nullptr;
        }
        else{
          if(strlen(expression[i]) == 2){
            currOp = '^';
            
          }
          else{ 
            currOp = expression[i][0];
          }
          endingOp = false; 
        }   
      }
    if(endingOp){
      return nullptr;
    }
    return leftValue;
    
  }

};
#endif //_FACTORY_HPP_
