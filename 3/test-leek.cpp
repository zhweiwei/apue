#include "apue.h"

int main(){
  int fd;
  fd = open("test_lseek",O_RDWR);
  if(fd < 0){
    std::cout << "error "<<std::endl;
    return -1;
  }
  
  off_t l = lseek(fd,10000,SEEK_END);
  

}
