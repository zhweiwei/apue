#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

#include <iostream>

using std::endl; using std::cout; using std::cin;using std::string; 

int testlock(int fd,int start,int len){
  struct flock flk;
  int err;
  flk.l_type = F_WRLCK;
  flk.l_start = start;
  flk.l_whence = SEEK_SET;
  flk.l_len = len;
  err = fcntl(fd,F_GETLK,&flk);
  if(err < 0) cout <<errno <<" getlock "<<endl;
  if(flk.l_type == F_UNLCK) return 0;
  return flk.l_pid;
}

int main(int argc,char* argv[]){
  if(argc < 4){
    cout << "have four"<<endl;
    return 0;
  }
  int fd = open(argv[1],O_RDONLY);
  cout <<"testlock = "<< testlock(fd,atoi(argv[2]),atoi(argv[3]))<<endl;
  close(fd);
  return 0;
}
