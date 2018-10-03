#include "apue.h"
#include <string>

using std::string;
using std::endl;
using std::cout;
using std::cin;

int system(const string& cmdstring){
  pid_t pid;
  int status;

  if(cmdstring.empty())
  return 1;

  if((pid = fork()) < 0)
    status = -1;
  else if(pid == 0){
    execl("/bin/sh","sh","-c",cmdstring.c_str(),(char*)0);
    _exit(127);
  }else{
    while(waitpid(pid,&status,0) <0){
    if(errno != EINTR){
    status = -1;
    break;
    }
  }
  }
return status;
}

int main(){
  int status;
  if((status = system("date")) < 0)
    cout<< "system error"<<endl;
}
