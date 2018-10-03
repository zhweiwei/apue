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

#define ERR_EXIT(msg) do { perror(msg); exit(1); } while(0)
#define IO_SIGNAL SIGUSR1

void handler(int sig, siginfo_t *info, void *ucontext) {
  int ret;
  printf("receive signal: %d\n", sig);
  struct aiocb *my_aiocb =(struct aiocb *)( info->si_value.sival_ptr);
  while(aio_error(my_aiocb) == EINPROGRESS) {
    write(STDOUT_FILENO, ".", 1); 
  }

  ret = aio_return(my_aiocb);
  if (ret < 0) ERR_EXIT("aio_return");

  printf("content: %s\n", (char*)(my_aiocb->aio_buf));
  exit(0);
}

int main() {
  int fd, ret;
  struct aiocb my_aiocb;
  char buf[64];

  bzero((char*)&my_aiocb, sizeof(struct aiocb));
  struct sigaction sa; 
  sigemptyset(&sa.sa_mask);
  sa.sa_flags = SA_SIGINFO;
  sa.sa_sigaction = handler;
  sigaction(IO_SIGNAL, &sa, NULL);

  my_aiocb.aio_buf = buf;
  my_aiocb.aio_fildes = STDIN_FILENO;
  my_aiocb.aio_nbytes = 64; 
  my_aiocb.aio_offset = 0;
  my_aiocb.aio_sigevent.sigev_notify = SIGEV_SIGNAL;
  my_aiocb.aio_sigevent.sigev_signo = IO_SIGNAL;
  my_aiocb.aio_sigevent.sigev_value.sival_ptr = &my_aiocb;

  ret = aio_read(&my_aiocb);
  if (ret < 0) ERR_EXIT("aio_read");

  while(1) {
    pause();
  }

  return 0;
}



