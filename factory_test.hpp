#ifndef _FACTORY_TEST_HPP_
#define _FACTORY_TEST_HPP_

#include "gtest/gtest.h"
#include "factory.hpp"
#include <cstring>

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
  delete test;
  delete A;
  delete B;
  delete root;

}

TEST(AddTest, stringifyTest) {

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


 EXPECT_EQ(test->parse(expression, 4)->stringify(), root->stringify());
  delete test;
  delete A;
  delete B;
  delete root;

}

TEST(SubtrationTest, EvaluateZero) {
  Factory* test = new Factory();
  char** expression = new char*[4];

  char location[7] = "./main"; 
  expression[0] = new char[strlen(location) + 1];
  strcpy(expression[0],location);

  char value1[2] = "7"; 
  expression[1] = new char[strlen(value1) + 1];
  strcpy(expression[1], value1);

  char op1[2] = "-"; 
  expression[2] = new char[strlen(op1) + 1];
  strcpy(expression[2], op1);

  char value2[2] = "0"; 
  expression[3] = new char[strlen(value2) + 1];
  strcpy(expression[3], value2);

  Base* A = new Op(7);
  Base* B = new Op(0);
  Base* root  = new Sub(A, B);

  EXPECT_EQ(test->parse(expression, 4)->evaluate(), root->evaluate());
  delete test;
  delete A;
  delete B;
  delete root;
}

TEST(SubtractionTest, stringifyTest) {
  Factory* test = new Factory();
  char** expression = new char*[4];

  char location[7] = "./main"; 
  expression[0] = new char[strlen(location) + 1];
  strcpy(expression[0],location);

  char value1[2] = "7"; 
  expression[1] = new char[strlen(value1) + 1];
  strcpy(expression[1], value1);

  char op1[2] = "-"; 
  expression[2] = new char[strlen(op1) + 1];
  strcpy(expression[2], op1);

  char value2[2] = "0"; 
  expression[3] = new char[strlen(value2) + 1];
  strcpy(expression[3], value2);

  Base* A = new Op(7);
  Base* B = new Op(0);
  Base* root  = new Sub(A, B);

  EXPECT_EQ(test->parse(expression, 4)->stringify(), root->stringify());
  delete test;
  delete A;
  delete B;
  delete root;
}

TEST(MultTest, EvaluateZero) {
  Factory* test = new Factory();
  char** expression = new char*[4];

  char location[7] = "./main"; 
  expression[0] = new char[strlen(location) + 1];
  strcpy(expression[0],location);

  char value1[2] = "7"; 
  expression[1] = new char[strlen(value1) + 1];
  strcpy(expression[1], value1);

  char op1[2] = "*"; 
  expression[2] = new char[strlen(op1) + 1];
  strcpy(expression[2], op1);

  char value2[2] = "0"; 
  expression[3] = new char[strlen(value2) + 1];
  strcpy(expression[3], value2);

  Base* A = new Op(7);
  Base* B = new Op(0);
  Base* root  = new Mult(A, B);

  EXPECT_EQ(test->parse(expression, 4)->evaluate(), root->evaluate());
  delete test;
  delete A;
  delete B;
  delete root;
}

TEST(MultTest, stringifyTest) {
  Factory* test = new Factory();
  char** expression = new char*[4];

  char location[7] = "./main"; 
  expression[0] = new char[strlen(location) + 1];
  strcpy(expression[0],location);

  char value1[2] = "7"; 
  expression[1] = new char[strlen(value1) + 1];
  strcpy(expression[1], value1);

  char op1[2] = "*"; 
  expression[2] = new char[strlen(op1) + 1];
  strcpy(expression[2], op1);

  char value2[2] = "0"; 
  expression[3] = new char[strlen(value2) + 1];
  strcpy(expression[3], value2);

  Base* A = new Op(7);
  Base* B = new Op(0);
  Base* root  = new Mult(A, B);

  EXPECT_EQ(test->parse(expression, 4)->stringify(), root->stringify());
  delete test;
  delete A;
  delete B;
  delete root;
}

TEST(DivTest, divide) {
  Factory* test = new Factory();
  char** expression = new char*[4];

  char location[7] = "./main"; 
  expression[0] = new char[strlen(location) + 1];
  strcpy(expression[0],location);

  char value1[2] = "4"; 
  expression[1] = new char[strlen(value1) + 1];
  strcpy(expression[1], value1);

  char op1[2] = "/"; 
  expression[2] = new char[strlen(op1) + 1];
  strcpy(expression[2], op1);

  char value2[2] = "8"; 
  expression[3] = new char[strlen(value2) + 1];
  strcpy(expression[3], value2);

  Base* A = new Op(4);
  Base* B = new Op(8);
  Base* root  = new Div(A, B);

  EXPECT_EQ(test->parse(expression, 4)->evaluate(), root->evaluate());
  delete test;
  delete A;
  delete B;
  delete root;
}

TEST(DivTest, stringifyTest) {
  Factory* test = new Factory();
  char** expression = new char*[4];

  char location[7] = "./main"; 
  expression[0] = new char[strlen(location) + 1];
  strcpy(expression[0],location);

  char value1[2] = "4"; 
  expression[1] = new char[strlen(value1) + 1];
  strcpy(expression[1], value1);

  char op1[2] = "/"; 
  expression[2] = new char[strlen(op1) + 1];
  strcpy(expression[2], op1);

  char value2[2] = "8"; 
  expression[3] = new char[strlen(value2) + 1];
  strcpy(expression[3], value2);

  Base* A = new Op(4);
  Base* B = new Op(8);
  Base* root  = new Div(A, B);

  EXPECT_EQ(test->parse(expression, 4)->stringify(), root->stringify());
  delete test;
  delete A;
  delete B;
  delete root;
}

TEST(DivTest, EvaluateZero) {
  Factory* test = new Factory();
  char** expression = new char*[4];

  char location[7] = "./main"; 
  expression[0] = new char[strlen(location) + 1];
  strcpy(expression[0],location);

  char value1[2] = "7"; 
  expression[1] = new char[strlen(value1) + 1];
  strcpy(expression[1], value1);

  char op1[2] = "/"; 
  expression[2] = new char[strlen(op1) + 1];
  strcpy(expression[2], op1);

  char value2[2] = "0"; 
  expression[3] = new char[strlen(value2) + 1];
  strcpy(expression[3], value2);

  EXPECT_TRUE(test->parse(expression, 4) == nullptr);
  delete test;
}

TEST(PowTest, EvaluateZero) {
  Factory* test = new Factory();
  char** expression = new char*[4];

  char location[7] = "./main"; 
  expression[0] = new char[strlen(location) + 1];
  strcpy(expression[0],location);

  char value1[2] = "7"; 
  expression[1] = new char[strlen(value1) + 1];
  strcpy(expression[1], value1);

  char op1[3] = "**"; 
  expression[2] = new char[strlen(op1) + 1];
  strcpy(expression[2], op1);

  char value2[2] = "0"; 
  expression[3] = new char[strlen(value2) + 1];
  strcpy(expression[3], value2);

  Base* A = new Op(7);
  Base* B = new Op(0);
  Base* root  = new Pow(A, B);

  EXPECT_EQ(test->parse(expression, 4)->evaluate(), root->evaluate());
  delete test;
  delete A;
  delete B;
  delete root;
}

TEST(PowTest, stringifyTest) {
  Factory* test = new Factory();
  char** expression = new char*[4];

  char location[7] = "./main"; 
  expression[0] = new char[strlen(location) + 1];
  strcpy(expression[0],location);

  char value1[2] = "7"; 
  expression[1] = new char[strlen(value1) + 1];
  strcpy(expression[1], value1);

  char op1[3] = "**";
  expression[2] = new char[strlen(op1) + 1];
  strcpy(expression[2], op1);

  char value2[2] = "0"; 
  expression[3] = new char[strlen(value2) + 1];
  strcpy(expression[3], value2);

  Base* A = new Op(7);
  Base* B = new Op(0);
  Base* root  = new Pow(A, B);

  EXPECT_EQ(test->parse(expression, 4)->stringify(), root->stringify());
  delete test;
  delete A;
  delete B;
  delete root;
}

#endif //_FACTORY_TEST_HPP_
