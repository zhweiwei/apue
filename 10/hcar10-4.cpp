#include "apue.h"
#include <isotream>
#include <sys/wait.h>

using std::endl; using std::cout; using std::cin;using std::string;

static void sig_cld(int);

int main(){
  pid_t pid;
  if(signal(SIGCLD,sig_cld) ==SIG_ERR){
    cout<<"signal error"<<endl;
  }
  if((pid = fork()) < 0){
    cout<<"fork error"<<endl;
  }else if(pid == 0){
    sleep(2);
    _exit(0);
  }
  pause();
  exit(0);
}

static void
sig_cld(int signo){
  pid_t pid;
  int status;

  cout<<"SIGCLD received"<<endl;

  if(signal(SIG_CLD,sig_cld) == SIG_ERR)
  cout<<"signal error"<<endl;

  if((pid = wait(&status)) < 0)
    cout<< "wait error"<<endl;

  cout <<"pid = "<<pid<<endl;
}
