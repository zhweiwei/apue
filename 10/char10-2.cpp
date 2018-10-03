#include "apue.h"

using std::endl; using std::cout; using std::cin;using std::string;

static void sig_usr(int);

int main(){
  if(signal(SIGUSR1,sig_usr) == SIG_ERR)
    cout<< "can't catch SIGUSR1"<<endl;

  if(signal(SIGUSR2,sig_usr) == SIG_ERR)
    cout << "can't catch SIGUSR2"<<endl;

  for(;;) pause();  
}

static void 
sig_usr(int signo){
  if(signo == SIGUSR1)
    cout<<"receiced SIGUSR1"<< endl;

  else  if(signo == SIGUSR2)
    cout<<"received SIGUSR2"<<endl;
  else
    cout<< "received signal "<< signo <<endl;
}
