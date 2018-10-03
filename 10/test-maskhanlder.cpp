#include <signal.h>
#include <stdlib.h>
#include <iostream>
#include <unistd.h>

using std::endl; using std::cout; using std::cin;using std::string;

static void handler(int);
static void sig_int(int);

int
main()
{
  if(signal(SIGQUIT,handler) == SIG_ERR) cout <<" signal error"<<endl;
  if(signal(SIGINT,sig_int) == SIG_ERR) cout<<"signale error"<<endl;  
  pause();
  cout<<"pause over"<<endl;
}

static void
handler(int signo)
{
cout <<"sigquit cacthed and begin sleep "<<endl;
sigset_t st;
if(sigpending(&st)< 0)cout <<"sigpending error"<<endl;
if(sigismember(&st,SIGQUIT))cout << "sigint local berfor"<<endl;
sleep(5);
cout<<"sleep over"<<endl;
if(sigpending(&st)< 0)cout <<"sigpending error"<<endl;
if(sigismember(&st,SIGQUIT))cout << "sigint local after"<<endl;
cout<<"sleep 2 seconds"<<endl;
sleep(2);
cout<<"exit handler"<<endl;
}
static void
sig_int(int signo)
{
cout <<"sigint cacthed and begin sleep "<<endl;
sigset_t st;
if(sigpending(&st)< 0)cout <<"sigpending error"<<endl;
if(sigismember(&st,SIGINT))cout << "sigint local berfor"<<endl;
sleep(5);
cout<<"sleep over"<<endl;
if(sigpending(&st)< 0)cout <<"sigpending error"<<endl;
if(sigismember(&st,SIGINT))cout << "sigint local after"<<endl;
cout<<"sleep 2 seconds"<<endl;
sleep(2);
cout<<"exit handler"<<endl;
}
