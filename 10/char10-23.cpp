#include <signal.h>
#include <unistd.h>

#include <iostream>

using std::endl; using std::cout; using std::cin;using std::string;
volatile sig_atomic_t quitflag;
static void
sig_int(int signo)
{
    if(signo == SIGINT) cout <<" sigint ";
    if(signo == SIGQUIT){ 
    cout <<" sigquit ";
    quitflag = 1;
    }
    cout<<endl;
}

int 
main()
{
    sigset_t newmask,oldmask,zeromask;
    if(signal(SIGINT,sig_int) == SIG_ERR) cout << "signal error"<<endl;
    if(signal(SIGQUIT,sig_int) == SIG_ERR) cout<< "signal error"<<endl;

    sigemptyset(&newmask);
    sigemptyset(&zeromask);
    sigaddset(&newmask,SIGQUIT);

    if(sigprocmask(SIG_BLOCK,&newmask,&oldmask) < 0) cout <<"sigprocmask error"<<endl;

    while(quitflag == 0)
    sigsuspend(&zeromask);

    quitflag =0;

    if(sigprocmask(SIG_SETMASK,&oldmask,NULL) < 0) cout <<"sigprocmask error"<<endl;

}
