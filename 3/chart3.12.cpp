#include "apue.h"

int main(){
int fd = open("chart3.12",O_RDWR);
  if(fd < 0){
    std::cout << "open file error" << std::endl;
    return -1;
  }
  char a[] = "sdfgbo";
  if(write(fd,a,sizeof(a)) < 0){
    std::cout << "write file error"<< std::endl;
    return -1;
  }
  int fd2 = dup(fd);
  if(write(fd2,a,sizeof(a)) < 0){
    std::cout<< "write file2 error" << std::endl;
    return -1;
  }
  close(fd);
  close(fd2);
}
