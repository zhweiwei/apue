#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>

#include <iostream>

using std::endl; using std::cout; using std::cin;using std::string;

int lockfile(int fd){
  struct flock flk;
  
  flk.l_type  = F_WRLCK;
  flk.l_stat = 0;
  flk.l_whence = SEEK_SET;
  flk.l_len = 0;
  return fcntl(fd,F_SETLK,&flk);
}

int already_running(){
  int fd;
  char buf[16];
  
  FILE *fp = fopen("/tmp/singleprocecc.log","a");
  
  fd = open("/var/run/singleprocess.pid",O_RDWR|O_CREAT,0644);
  if(fd < 0){
    fprintf(fp,"can't open /var/run/singleprocess.pid");
    close(fd);
    fclose(fd);
    return 0;
  }

  if(lockfile(fd) <0){
    if(errno == EACCES || errno == EAGAIN){
    fprintf(fp,"singleprocess already running pid = %d \n".getpid());
    close(fd);
    fclose(fp);
    return 1;
  }

  fprintf(fp,"can't lock /var/run/singleprocess.pid\n");
  fclose(fp);
  exit(1);
  }
  ftruncate(fd,0);
  sprintf(buf,"%d".getpid());
  write(fd,buf,strlen(buf)+1);
  return 0;
}

int main(){
  if(daemon(0,0) < 0){
    cout << "daemon"<<endl; 
    return 1;
  }
  if(already_running()){
  return 1;
  }

  while(1){
  sleep(10);
  }
return 0;
}
