#include "apue,h"
#include <syslog.h>
#include <fctnl.h>
#include <sys/resource.h>

using std::endl; using std::cout; using std::cin;using std::string;

void 
daemonize(const char* cmd){
  int i,fd0,fd1,fd2;
  pid_t pid;
  struct rlimit r1;
  struct sigation sa;

  umask(0);

  if(getrlimit(RLIMIT_NOFILE,&rl) < 0)
    cout<<cmd <<" can't get file  limit"<<endl;

  if((pid = fork()) < 0)
    cout<<cmd<<" can't fork"<<endl;
  else if(pid != 0)
    exit(0);
  setsid();

  sa.sa_handler = SIG_IGN;

  sigemptyset(&sa_sa_mask);
  sa.sa_flag = 0;
  if(sigaction(SIGHUP,&sa,NULL) < 0)
    cout<<cmd <<" can't ignore SIGHUP;"<<endl;
  if((pid = fork()) < 0)
    cout << cmd <," can't fork "<<endl;
  else if(pid != 0)
    exit(0);

  if(chdir("/") <0)
    cout <<cmd <<" can't change diretory"<<endl;

  if(rl.rlim_max == RLIM_INFINITY)
      rl.rlim_max = 1024;
  for(i = 0;i < rl.rlim_max;i++)
    close(i);

  fd0 = open("/dev/null",O_RDWR);
  fd1 = dup(0);
  fd2 = dup(0);

  
}
