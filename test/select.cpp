#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/select.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <signal.h>

#include <iostream>

using std::endl; using std::cout; using std::cin;using std::string;

int process(const char *prompt,int fd){
  int n;
  char buf[64];
  char line[64];
  n = read(fd,buf,64);
  if(n < 0){
    cout << "read "<<endl;
  }else if(n == 0){
    sprintf(line,"%s closed \n",prompt);
    cout<<line;
    return 0;
  }else if(n > 0){
    buf[n] = 0;
    sprintf(line,"%s say: %s \n",prompt,buf);
    cout << line<<endl;
  }
  return n;
}

int 
main(){
  int n,res;
  char buf[64];
  
  fd_set st;
  FD_ZERO(&st);

  int fd0 = STDIN_FILENO;
  int fd1 = open("a.fifo",O_RDONLY);
  cout<< "open pipe:fd = "<<fd1<<endl;
  int fd2 = open("b.fifo",O_RDONLY);
  cout <<" open pipe fd = "<<fd2 <<endl;

  FD_SET(fd0,&st);
  FD_SET(fd1,&st);
  FD_SET(fd2,&st);

  int maxfd = fd2 + 1;
  
  while(1){
    fd_set tmpset = st;
    res = select(maxfd,&tmpset,NULL,NULL,NULL);

  if(res < 0){
    cout <<"select "<<endl;
  }else if ( res == 0)
    continue;

  if(FD_ISSET(fd0,&tmpset)){
    n = process("fd0",fd0);
    if(n == 0) FD_CLR(fd0,&st);
    }
  if(FD_ISSET(fd1,&tmpset)){
    n = process("fd1",fd1);
    if(n == 0) FD_CLR(fd1,&st);
    }
  if(FD_ISSET(fd2,&tmpset)){
    n = process("fd2",fd2);
    if(n == 0) FD_CLR(fd2,&st);
    }
  }
}
