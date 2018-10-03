#include "apue.h"
#include <iostream>

using std::endl; using std::cout; using std::cin;using std::string;

void daemonize(){
  pid_t pid;
  int i,fd0,fd1,fd2;
  struct rlimit r1;

  getrlimit(RLIMIT_NOFILE,&r1);
  
  umask(0);

  if((pid = fork()) < 0){
    err<< "fork";
    exit(-1);
  }
  else if(pid >0){
    exit(0);
  }

  if(setsid() <0){
    err<< "setsid";
    exit(-1);
  }
  struct sigaction sa;
  sa.sa_handler = SIG_IGN;
  sigemptyset(&sa.sa_mask);
  sa.sa_flags = 0;
  if(sigaction(SIFHUP,@sa,NULL) < 0){
    err<<"sigaction";
    exit(-1);
  }
  if(chdir("/") < 0){
    err<< "chdir";
    exit(-1);
  }
  if(r1,rlim_max = RLIM_INFINITY){
    r1.rlim_max = 1024;
  }
  for(i =0;i < r1.lim_max;++i){
  close(i);
  }

  fd0 = open("/dev/null",O_RDWR);
  fd1 = dup(0);
  fd2 = dup(0);
}


