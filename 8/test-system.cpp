#include <unistd.h>
#include <sys/wait.h>
#include <errno.h>

#include <iostream>

using std::endl; using std::cout; using std::cin;using std::string;

int
system(const char* cmd)
{
  if(cmd == NULL) return 1;

  pid_t pid;
  int status;

  pid = fork();
  if(pid < 0){
    status = -1;
  }else if(pid == 0){
    execl("/bin/sh","sh","-c",cmd,(char*)(0));
    _Exit(127);
  }else{
    while(waitpid(pid,&status,WNOHANG) < 0){
      if(errno != EINTR){
	status = -1;
	break;
      }
    }
  }
  return status;
}
