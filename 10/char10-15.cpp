#include <unistd.h>
#include <signal.h>
#include <stdlib.h>

#include <iostream>


using std::endl; using std::cout; using std::cin;using std::string;

static void sig_quit(int);

int 
main()
{
 sigset_t newmask,oldmask,pendmask;

 if(signal(SIGQUIT,sig_quit) == SIG_ERR){
 cout<<"signal error"<<endl;
 exit(0);
 }
sigemptyset(&newmask);
sigaddset(&newmask,SIGQUIT);
if(sigprocmask(SIG_BLOCK,&newmask,&oldmask)< 0){
  cout<<"sigprocmask error"<<endl;
}
cout<<"begin sleep"<<endl;
sleep(5);
if(sigpending(&pendmask)< 0) cout<<"sigpending error"<<endl;

if(sigismember(&pendmask,SIGQUIT)) cout <<"sigquit is menber"<<endl;
sleep(5);
cout<<"begin sigsetmask "<<endl;
sigdelset(&pendmask,SIGQUIT);
if(sigprocmask(SIG_SETMASK,&pendmask,NULL)<0)cout <<"sigsetmask error"<<endl;
sleep(5);
exit(0);

}

static void
sig_quit(int signo)
{
  cout<<"catch SIGQUIT"<<endl;

}
