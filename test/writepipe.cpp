#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include <iostream>

using std::endl; using std::cout; using std::cin;using std::string;

int main(int argc,char* argv[]){
  if(argc < 2){
    cout<<" have two"<<endl;
    return 0;
  }

 char buf[64];
  int n;
  int fd = open(argv[1],O_RDWR|O_APPEND);
  if(fd < 0){
  cout << "open pipe"<<endl;
    return 1;
  }

  while(1){
   n =  read(STDIN_FILENO,buf,64);
    write(fd,buf,n);
  }
  return 1;
}
