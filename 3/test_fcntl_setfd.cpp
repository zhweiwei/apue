#include "apue.h"
#include <iostream>

using std::endl; using std::cout; using std::cin;using std::string;

int main(){
  int fd = open("text.txt",O_RDWR);
  cout << "fd = "<<fd <<endl;
  
  int fd2 = fcntl(fd,F_SETFD,12);
  cout <<"fd = "<<fd<<endl;
  cout <<"fd2 = " <<fd2 <<endl;
}
