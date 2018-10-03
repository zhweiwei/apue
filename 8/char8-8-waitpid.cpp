#include "apue.h"

using std::endl;
using std::cout;
using std::cin;

int main(){
  pid_t pid;
if((pid = fork()) < 0){
  cout <<"fork error "<<endl;
  return -1;
  }else if(pid == 0){
    if((pid = fork()) < 0){
      cout <<"fork 2 error"<<endl;
      return -1;
    }else if(pid >0){
      exit(0);
    }
  sleep(2);
  cout <<"second child parent pid = "<<getppid()<<endl;
  exit(0);
  }
if(waitpid(pid,NULL,0) != pid)
    cout << "waitpid error"<<endl;
  exit(0);
}
