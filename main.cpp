#include "factory.hpp"
#include "base.hpp"
#include <iostream>

int main(int argc, char**argv){
  Factory* expTree = new Factory();

  for(int i = 0; i < argc; i++){
    cout << argv[i] << endl;
  }

  Base* output = expTree->parse(argv, argc);

  if(output){
    cout << output->stringify() << " = " << output->evaluate() << endl;
  }
  else{
    cout << "Expression tree is incorrect" << endl;
  }
  return 0;
}
