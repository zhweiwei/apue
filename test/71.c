#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

void handler(int sig) {
  if (sig == SIGTTIN) {
    printf("hello SIGTTIN\n");
  }
  if (sig == SIGTTOU) {
    printf("hello SIGTTOU\n");
    exit(0);
  } 
}

int main(int argc, char* argv[]) {
  int len;
  char buf[64];

  signal(SIGTTIN, handler);
  signal(SIGTTOU, handler);

  while(1) {
    len = read(STDIN_FILENO, buf, 64);
    printf("len=%d\n",len);
    if (len > 0) {
      write(STDOUT_FILENO, buf, len);
    }   
    else {
      perror("read");
    }   
  }
  return 0;
}

