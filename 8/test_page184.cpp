#include "apue.h"

using std::endl; using std::cout; using std::cin;using std::string;

int main(){
  int fd = open("11",O_CREAT|O_RDONLY);
  pid_t pid;
  pid = fork();
  if(pid < 0){
  cout <<"fork error"<<endl;
  exit(0);
  }else if(pid == 0){
  int it =  lseek(fd,20,SEEK_SET);
  cout <<"child it = "<<it<<endl;
    exit(0);
  }
  sleep(2);
  int it = lseek(fd,0,SEEK_CUR);
  cout <<"parent it = "<<it<<endl;
  
}
