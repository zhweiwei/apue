#include "apue.h"
#include <fstream>

using std::cout;
using std::cin;

int main(int argv,char* argc[]){
  if(argv != 3){
    cout<< "no file"<< std::endl;
    return -1;
  }
  ifstream in(argc[1]);
  ofstream om(argc[2]);
  char a;
  while(a = in.get())
}
