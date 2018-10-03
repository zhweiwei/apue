#include "apue.h"
#include <pwd.h>

using std::endl; using std::cout; using std::cin;using std::string;

static void
my_alarm(int signo){
  struct passwd *rootptr;

  cout <<"in signal handler"<<endl;
  if((rootptr = getpwnam("root")) == NULL)
	cout<<"getpwnam  root error"<<endl;

    alarm(1);
}

int 
main(){
  struct passwd *ptr;
  if(signal(SIGALRM,my_alarm) == SIG_ERR)
    cout << "signal error"<<endl;
  alarm(1);

  for(;;){
    if((ptr = getpwnam("test")) == NULL)
      cout <<"getpwnam test error"<<endl;
      //pause(); 
    if(strcmp(ptr->pw_name,"test") != 0)
      cout<< "return value corrupted pw_name = "<<ptr->pw_name<<endl;
    else
      cout<<"return name "<<ptr->pw_name<<endl;
  }
}
