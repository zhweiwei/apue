#ifdef __cplusplus
extern "C" {
#endif

#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <aio.h>
#include <strings.h>
#include <errno.h>
#include <signal.h>

#ifdef __cplusplus
}
#endif

#include <iostream>
#define IO_SIGNAL SIGUSR1

using std::endl; using std::cout; using std::cin;using std::string;

void handler(int sig,siginfo_t *info,void *ucontext){
  int ret;
  cout <<"revice signal "<<sig<<endl;
    struct aiocb *my_aiocb = (struct aiocb *)(info->si_value.sival_ptr);
    //struct aiocb *my_aiocb = static_cast<struct aiocb *>(info->si_value.sival_ptr);
  while(aio_error(my_aiocb) == EINPROGRESS){
  write(STDOUT_FILENO,".",1);
  }
  
  ret = aio_return(my_aiocb);
  if(ret < 0) cout<< "aio_return"<<endl;

  cout <<"handler content "<<my_aiocb->aio_buf<<endl;
  exit(0);
}


int main(){
  int fd,ret;
  char buf[64];  
  struct aiocb my_aiocb;

  bzero((char*)&my_aiocb,sizeof(struct aiocb));

  struct sigaction sa;
  sigemptyset(&sa.sa_mask);
  sa.sa_flags = SA_SIGINFO;
  sa.sa_sigaction = handler;
  sigaction(IO_SIGNAL,&sa,NULL);

  my_aiocb.aio_buf = buf;
  my_aiocb.aio_fildes = STDIN_FILENO;
  my_aiocb.aio_nbytes = 64;
  my_aiocb.aio_offset = 0;

  my_aiocb.aio_sigevent.sigev_notify = SIGEV_SIGNAL;
  my_aiocb.aio_sigevent.sigev_signo = IO_SIGNAL;
  my_aiocb.aio_sigevent.sigev_value.sival_ptr = &my_aiocb;
  
  ret = aio_read(&my_aiocb);
  if(ret < 0) cout<<" aio_read "<<endl;

  while(1){
  pause ();
  }

}
