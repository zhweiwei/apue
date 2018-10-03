#include "apue.h"
#include <iostream>

using std::endl; using std::cout; using std::cin;using std::string;

int main(){
  int fd = open("text.txt",O_RDWR);
  char buf1[4];
  char buf2[4];
  lseek(fd,2,SEEK_SET);
  pread(fd,buf1,3,0);
  read(fd,buf2,3);
  int off = lseek(fd,0,SEEK_CUR);
  cout <<"off = "<<off<<endl;
  buf1[3] = 0;
  buf2[3] = 0;
  cout<< "buf1 "<<buf1<<endl;
  cout<<"buf2 "<<buf2<<endl;
  close(fd);
}
