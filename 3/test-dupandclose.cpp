#include "apue.h"

using std::cout;
using std::cin;
using std::endl;

int main(){
  int fd = open("1.txt",O_RDWR|O_CREAT);
  int fd2 = dup(fd);
  close(fd);
  int s = lseek(fd2,10,SEEK_SET);
  cout << s <<endl;
  close(fd2);
}
