#include "apue.h"

using std::endl;
using std::cout;
using std::cin;

int main(){
  pid_t pid;
  if((pid = fork())<0){
  cout<<"fork error"<<endl;
  return -1;
  }else if(pid == 0){
  if(execl("/root/wei/C++/unix/8/testecho","test1","test2",(char*)0) < 0){
    cout << "execl error"<<endl;
    return -1;
  }
}
  if(waitpid(pid,NULL,0) < 0)
      cout<< "waitpid error"<<endl;
  exit(0);
}
