#include "apue.h"

int main(){
  int fd;
  fd = open("test.1",O_RDWR); 
  if(fd < 0){
    std::cout << "open file error"<< std::endl;
    return -1;
  }
  if(lseek(fd,10000,SEEK_END) < 0){
    std::cout << "lseek error"<<std::endl;
    return -1;
  }
  const char* p = "sdfho";
  if(write(fd,p,sizeof(p)) < -1){
    std::cout << "wirte file error"<<std::endl;
    return -1;
  }

}
