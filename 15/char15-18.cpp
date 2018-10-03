#include "apue.h"
#include <iostream>

#define MAXLINE 4096
using std::endl; using std::cout; using std::cin;using std::string;

static void sig_pipe(int);

int main(){
  int n,fd1[2],fd2[2];
  pid_t pid;
  char line[MAXLINE];

  if(signal(SIGPIPE,sig_pipe) == SIG_ERR)
    cout<< "signal error"<<endl;

  if(pipe(fd1) <0 || pipe(fd2) < 0)
    cout <<"pipe error"<<endl;

  if((pid = fork()) <0){
    cout <<"fork error"<<endl;
  }else if(pid >0){
  close(fd1[0]);
  close(fd2[1]);

  while(fgets(line,MAXLINE,stdin) != NULL){
      n = strlen(line);
      if(write(fd1[1],line,n) != n)
	cout<<"write error to pipe"<<endl;
      if((n =read(fd2[0],line,MAXLINE)) < 0)
	cout<<"read error from pipe"<<endl;
      if(n == 0){
      cout<<"child closed pipe"<<endl;
      break;
      }
      line[n] = 0;
    if(fputs(line,stdout) == EOF)
    cout<<"fput error"<<endl;
    }
  }
}
