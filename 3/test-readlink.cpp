#include "apue.h"

using std::endl; using std::cout; using std::cin;using std::string;

int main(){
  char buf[64];
  int  f = readlink("./test/1.txt",buf,63);
  buf[64] =0;
  cout <<"sizeof "<<strlen(buf)<<endl;
  cout << buf << endl;
  cout <<"f = "<<f<<endl;
}
