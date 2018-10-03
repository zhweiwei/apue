#include "apue.h"
#include <iostream>

using std::endl; using std::cout; using std::cin;using std::string;

int main(){
  int fd = open("test",O_RDONLY);
  int a =  linkat(fd,"3.txt",fd,"1.txt",0);
  int b =  linkat(fd,"3.txt",fd,"4.txt",AT_SYMLINK_FOLLOW);
  cout << "a = "<<a<<endl;
  cout<<" b= "<<b <<endl;
  cout <<AT_SYMLINK_FOLLOW<<endl;
  cout <<"fd = "<<fd<<endl;
}
