#include "apue.h"
using std::endl; using std::cout; using std::cin;

int main(){
  int p = open("a.txt",O_RDWR|O_CREAT);
  off_t v = lseek(p,10,SEEK_SET);
  cout <<v<<endl;
  v = 0;
  v = lseek(p,0,SEEK_CUR);
cout <<v<<endl;
}
