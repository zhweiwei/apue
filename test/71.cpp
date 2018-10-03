#include "apue.h"
#include <iostream>

using std::endl; using std::cout; using std::cin;using std::string;

void handler(int sig){
  if(sig == SIGTTIN){
    cout <<"hello SIGTTIN"<<endl;
  }
  if(sig == SIGTTOU){
    cout << "hello SIGTTOU"<<endl;
    exit(0);
  }
}
int main(){
  int len;
  char buf[64];

  signal(SIGTTIN,handler);
  signal(SIGTTOU,handler);

  while(1){
    len = read(STDIN_FILENO,buf,64);
    if(len < 0) exit(0);
  if(len > 0)
    write(STDOUT_FILENO,buf,len);
  else
    cout << "error read"<<endl;
  }
  return 0;

}
