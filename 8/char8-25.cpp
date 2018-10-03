#include "apue.h"

int main(){
  std::cout<<"real uid "<<getuid()<<" effective uid "<<geteuid()<<std::endl;
  exit(0);
}
