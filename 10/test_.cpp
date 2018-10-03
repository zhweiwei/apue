#include <unistd.h>
#include <signal.h>
#include <iostream>

using std::endl; using std::cout; using std::cin;using std::string;

static void sig_int(int);
void pr_mask(const char*);
int 
main()
{
  sigset_t newmask,oldmask,waitmask;
  pr_mask("program start: ");
  if(signal(SIGQUIT,sig_int) == SIG_ERR) cout <<"signal sigint error"<<endl;
  sigemptyset(&waitmask);
  sigaddset(&waitmask,SIGINT);
  sigemptyset(&newmask);
  sigaddset(&newmask,SIGQUIT);

  if(sigprocmask(SIG_BLOCK,&newmask,&oldmask) < 0) cout << "sigprocmask error"<<endl;

  pr_mask("in critical region: ");
  if(sigsuspend(&waitmask) != -1) cout <<"sigsuspend error"<<endl;
  pr_mask("after sigsuspen: ");
  if(sigprocmask(SIG_SETMASK,&oldmask,NULL) < 0) cout <<"sig_setmask error"<<endl;

  pr_mask("program exit:");
}

static void
sig_int(int signo)
{
  pr_mask("\nin sig int: ");
}

void 
pr_mask(const char* str)
{
  sigset_t st;
  cout <<str;
  sigprocmask(0,NULL,&st);
  if(sigismember(&st,SIGINT)) cout <<" SIGINI ";
  if(sigismember(&st,SIGQUIT)) cout <<" SIGQUIT ";
  if(sigismember(&st,SIGUSR1)) cout<<" siguquit ";
  cout <<endl;
}
