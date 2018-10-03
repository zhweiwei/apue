#include "apue.h"

using std::endl;
using std::cout;
using std::cin;

int main(int argc,char *argv[]){
  int i;
  char **ptr;
  extern char **environ;

  for(i = 0;i <argc ;i++){
    cout<< i <<" "<<argv[i]<<endl;
  }

  for(ptr = environ;*ptr !=0;ptr++){
    cout<<*ptr<<endl;
  }
}
