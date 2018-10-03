#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <errno.h>
#include <stdio.h>

#include <iostream>

using std::endl; using std::cout; using std::cin;using std::string;

int lock(int fd){
  cout<<"locking ..."<<endl;
  struct flock flk;
  int err;
  flk.l_type = F_WRLCK;
  flk.l_start = SEEK_SET;
  flk.l_whence = 2;
  flk.l_len = 2;
  err = fcntl(fd,F_SETLKW,&flk);
  if(err < 0) cout <<errno <<" lock"<<endl;
  cout << " locked..."<<endl;
  return err;
}

int unlock(int fd){
  cout <<"unlocking ..."<<endl;
  struct flock flk;
  flk.l_type = F_UNLCK;
  flk.l_start = SEEK_SET;
  flk.l_whence = 2;
  flk.l_len = 2;
  int err = fcntl(fd,F_SETLKW,&flk);
  if(err <0)cout <<"unlock error"<<endl;
  return err;
}

int 
main(){
  cout <<"pid = "<<getpid()<<endl;
  int fd = open("test",O_WRONLY);
  lock(fd);
  sleep(10);
  cout << "close fd2"<<endl;
  int fd2 = dup(fd);
  close(fd2);
  sleep(10);
  unlock(fd);
  close(fd);
  return 0;
}













