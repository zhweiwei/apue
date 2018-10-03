#include "apue.h"

using std::endl; using std::cout; using std::cin;using std::string;

int 
main()
{
  pid_t pid = fork();
  if(pid < 0){
  cout <<"fork error"<<endl;
  exit(0);
  }
  if(pid == 0){
  cout<<"this is child"<<endl;
  exit(0);
  }
  if(pid > 0){
  int status;
  wait(&status);
  cout <<"this is father"<<endl;
  sleep(2);
  exit(0);
  }
}
