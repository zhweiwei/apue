#include "apue.h"

using std::endl; 
using std::cout; 
using std::cin;

int main(int argc,char* argv[]){
  int status;
  if(argc < 2){
  cout<<"commend required"<<endl;
  return -1;
  }

  if((status = system(argv[1]) )< 0){
    cout<< "system error"<<endl;
    return -1;
  }
  exit(0);
}
