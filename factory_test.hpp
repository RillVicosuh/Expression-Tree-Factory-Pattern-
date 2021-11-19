#ifndef _FACTORY_TEST_HPP_
#define _FACTORY_TEST_HPP_

#include "gtest/gtest.h"
#include "factory.hpp"

TEST(AddTest, EvaluateZero) {
  Factory* test = new Factory();
  char** expression = new char*[4];

  char location[7] = "./main"; 
  expression[0] = new char[strlen(location) + 1];
  strcpy(expression[0],location);

  char value1[2] = "7"; 
  expression[1] = new char[strlen(value1) + 1];
  strcpy(expression[1], value1);

  char op1[2] = "+"; 
  expression[2] = new char[strlen(op1) + 1];
  strcpy(expression[2], op1);

  char value2[2] = "0"; 
  expression[3] = new char[strlen(value2) + 1];
  strcpy(expression[3], value2);

  Base* A = new Op(7);
  Base* B = new Op(0);

  Base* root  = new Add(A, B);

  EXPECT_EQ(test->parse(expression, 4)->evaluate(), root->evaluate());
}

#endif //_FACTORY_TEST_HPP_
