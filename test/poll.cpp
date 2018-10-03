#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <poll.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <signal.h>

#include <iostream>

using std::endl; using std::cout; using std::cin;using std::string;

void handler(int sig){
  if(sig = SIGINT)
    cout << "hello SIGINT"<<endl;
}

int process(char *prompt,int fd){
  int n ;
  char buf[64];
  char line[64];
  n = read(fd,buf,64);
  if(n < 0) cout<< "read"<<endl;
  else if(n == 0){
    sprintf(line," %s closed\n",prompt);
    cout<<line<<endl;
    return 0;
  }else if( n > 0){
    buf[n] = 0;
    sprintf(line," %s say: %s ",prompt,buf);
    cout << line<<endl;
  }
  return 0;
}

int main(){
  int i ,n, res;
  char buf[64];
  
  struct pollfd fds[4];
  
  if(SIG_ERR == signal(SIGINT,handler)){
  cout << "signal "<<endl;
  }
  
  int fd0 = STDIN_FILENO;
  int fd1 = open("a.fifo",O_RDONLY);
  cout<<" open pipe :fd  = "<<fd1<<endl;
  int fd2 = open("b.fifo",O_RDONLY);
  cout<< " open pipe:fd = "<<fd2<<endl;
  int fd3 = 100;

  fds[0].fd = fd0;
  fds[1].fd = fd1;
  fds[2].fd = fd2;
  fds[3].fd = fd3;
  
  for(i = 0;i < 4;i++)
    fds[i].events = POLLIN;

  while(1){
  res = poll(fds,4,-1);
  if(res < 0){
    if(errno == EINTR){
      cout <<"poll "<<endl;
      continue;
    }
    cout <<"poll "<<endl;
  }else if(res == 0) continue;

  for( i= 0; i < res;i++){
    if(fds[i].revents & POLLIN){
    sprintf(buf,"fd%d",i);
    n = process(buf,fds[i].fd);
    if(n == 0)fds[i].fd = -1;
    }
    if(fds[i].revents & POLLERR){
    cout<<"fd"<<i<<" Error"<<endl;
    fds[i].fd = -1;
    }

  if(fds[i].revents & POLLHUP){
  cout<<"fd"<<i<<" Hang up"<<endl;
  fds[i].fd = -1;
  }

  if(fds[i].revents &POLLNVAL){
  cout<<"fd"<<i<<" Invalid request "<<endl;
  fds[i].fd = -1;
  }
  }
  } 
}
