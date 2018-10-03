#include <unistd.h>
#include <stdio.h>
#include <cstdlib>
#include <iostream>

using std::endl; using std::cout; using std::cin;using std::string;

int main(){
  pid_t sid,pid;
  pid = fork();
  if(pid == 0){
    sid = getsid(getpid());
    cout<<"sid = "<< sid<<endl;

    sid = setsid();
    if(sid < 0){
      cout <<"setsid error"<<endl;
    }
    cout << "sid = " << sid<<endl;
  }
  while(1) sleep(1);
return 0;
}
