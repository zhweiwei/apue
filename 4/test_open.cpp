#include "apue.h"
#include <errno.h>
using std::endl; using std::cout; using std::cin;using std::string;

int 
main(){
  int fd= open("121",O_CREAT|O_RDWR,0666);
  int fd2= open("222",O_CREAT|O_RDWR,0666);
  if(fd < 0){ 
    cout << "open error "<<errno<<endl;
    return 0;
  }
  write(fd,"122",3);
  lseek(fd,1024,SEEK_CUR);
  write(fd,"333",3);
  char buf[64];
  lseek(fd,0,SEEK_SET);
  int n;
  int i = 0;
  while((n = read(fd,buf,64)) > 0){
    i = 0;
    while(i < n){
      if(buf[i] != 0){
	write(fd2,&buf[i],1);  
	}
    i++;
    }
  }
  cout << " i" << i<<endl;
}
