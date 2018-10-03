#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char* argv[]) {
  if (argc < 2) {
    printf("Usage: %s <fifoname>\n", argv[0]);
    return 1;
  }
  char buf[64];
  int n;
  int fd = open(argv[1], O_WRONLY);
  if (fd < 0) {
    perror("open pipe");
    return 1;
  }
  while(1) {
    n = read(STDIN_FILENO, buf, 64);
    write(fd, buf, n); 
  }
  return 0;

}
