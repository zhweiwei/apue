#include "apue.h"
#include <iostream>

using std::endl; using std::cout; using std::cin;using std::string;

int main(){
  int i = rename("./test/4.txt","5555.txt");
  cout <<"i = "<<i<<endl;

}
