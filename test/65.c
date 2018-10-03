#include "apue.h"

int main(){
  int pid,i;
  int group1,group2;

  setpgid(getpid(),getpid());
  group1 = getpgid(getpid());
  
  for(i =1;i <= 3;++i){
    pid = fork();
    if(pid == 0){
      if(i == 1){
      setpgid(getpid(),group1);
      }
      else if(i == 2){
	setpgid(getpid(),getpid());
	group2 = getgppid(getpid());
      }
      else if( i== 3){
	setpgid(getpid(),group2);
      }
   break();
    }
  else if(pid < 0){
    
  }
}
