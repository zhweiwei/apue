#include <unistd.h>
#include <setjmp.h>
#include <time.h>
#include <signal.h>
#include <iostream>
#include <stdlib.h>

using std::endl; using std::cout; using std::cin;using std::string;


static void sig_usr1(int);
static void sig_alrm(int);
static sigjmp_buf jmpbuf;
static volatile sig_atomic_t canjump;
void pr_mask(const char*);
int
main()
{
  if(signal(SIGUSR1,sig_usr1) == SIG_ERR) cout <<"signal error"<<endl;
  if(signal(SIGALRM,sig_alrm) == SIG_ERR) cout <<"signal sigalrm error"<<endl;

  pr_mask("starting main: ");
  if(sigsetjmp(jmpbuf,1)){
    pr_mask("ending main: ");
    exit(0);
  }
  canjump = 1;
  for(;;) pause();
}

static void
sig_usr1(int signo)
{
  time_t starttime;
  if(canjump == 0){
  return;
  }
  pr_mask("start sig_usr1: ");
  alarm(3);
  starttime = time(NULL);
  for(;;)
    if(time(NULL) > starttime+5)
      break;
  pr_mask("finishing sig_usr1: ");
  canjump = 0;
  siglongjmp(jmpbuf,1);
}

static void
sig_alrm(int signo)
{
  pr_mask("in sig_alrm: ");
}

void 
pr_mask(const char* str)
{
sigset_t sigset;
int errno_save;
if(sigprocmask(0,NULL,&sigset) < 0){ 
cout<<" sigpromask error"<<endl;
}else{
  cout<<str<<"  ";
  if(sigismember(&sigset,SIGINT)) cout<<"SIGINT ";
  if(sigismember(&sigset,SIGQUIT)) cout<<" SIGQUIT ";
  if(sigismember(&sigset,SIGALRM)) cout<<" SIGALRM ";
  cout<<endl;
}

}
