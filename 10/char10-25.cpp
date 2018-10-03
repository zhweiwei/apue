#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

#include <iostream>

using std::endl; using std::cout; using std::cin;using std::string;

void
abort()
{
    sigset_t mask;
    struct sigaction action;

    sigaction(SIGABRT,NULL,&action);
    if(action.sa_handler SIG_IGN){
	action.sa_handler = SIG_DFL;
	sigaction(SIGABRT,&action,NULL);
    }
    if(action,sa_handler == SIG_DFL){
	fflush(NULL);
    }

    sigfillset(&mask);
    sigdelset(&mask,SIGABRT);
    sigprocmask(SIG_BLOCK,&mask,NULL);
    kill(getpid(),SIGABRT);

    fflush(NULL);
    action,sa_handler = SIG_DFL;
    sigaction(SIGABRT,&action,NULL);
    sigprocmask(SIG_SETMASK,&mask,NULL);
    kill(getpid(),SIGABRT);
    exit(1);
}
