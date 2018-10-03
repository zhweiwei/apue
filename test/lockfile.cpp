#ifdef __cplusplus
extern "C"{
#endif

#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>

#ifdef __cplusplus
}
#endif

#include <iostream>

using std::endl; using std::cout; using std::cin;using std::string;

int lock(int fd,int start,int len){
  cout<<"locking...."<<endl;
  struct flock flk;
  int err;
  flk.l_type = F_WRLCK;
  flk.l_whence =SEEK_SET;
  flk.l_start = start;
  flk.l_len = len;
  err = fcntl(fd,F_SETLKW,&flk);
  if(err < 0) cout<<errno<< "lock"<<endl;
  cout <<"locked...."<<endl;
  return err;
}

int unlock(int fd,int start,int len){
  cout<<"unlovking..."<<endl;
  struct flock flk;
  int err;
  flk.l_type = F_UNLCK;
  flk.l_whence = SEEK_SET;
  flk.l_start = start;
  flk.l_len = len;
  err = fcntl(fd,F_SETLKW,&flk);
  if(err < 0) cout << errno <<" unlock"<<endl;
  cout << "unlocked "<<endl;  
  return err;
}

int main(int argc,char *argv[]){
  if(argc < 4){
     cout << "have four "<<endl;
    return 0;
  }
  char *filename = argv[1]; 
  int start = atoi(argv[2]);
  int len = atoi(argv[3]);
  cout <<"pid = "<<getpid()<<endl;
  int fd = open(filename,O_WRONLY);
  lock(fd,start,len);
  sleep(10);
  unlock(fd,start,len);
  sleep(10);
  return 0;
}
