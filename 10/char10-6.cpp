#include <sys/wait.h>
#include <unistd.h>
#include <iostream>
#include <sys/wait.h>
#include <stdlib.h>

using std::endl; using std::cout; using std::cin;using std::string;
using std::cerr;

static void cig_cl(int);

int 
main()
{
  pid_t pid;
  int status;
  pid = fork();
  if(signal(SIGCLD,cig_cl) == SIG_ERR){
    cout<<" sinal error"<<endl;
    exit(0);
  }
  if(pid < 0){
  cout <<"fork error"<<endl;
  exit(0);
  }else if(pid == 0){
    sleep(2);
    _exit(0);
  }

  pause();
  exit(0);

}

static void
cig_cl(int st)
{
  pid_t pid;
  int status;

  cout<<"sigcld received"<<endl;

  if(signal(SIGCLD,cig_cl) == SIG_ERR){
    cerr<<"child signal error";
  }

  if((pid = wait(&status)) < 0)
  cerr<<"wait error";

  cout<<"pid = "<<getpid()<<endl;
}
