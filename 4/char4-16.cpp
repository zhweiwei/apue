#include "apue.h"

int main(){
  int fd = open("tempfile",O_RDWR);
  if(fd < 0){
    std::cout <<"open file error"<<std::endl;
    return -1;
  }
  if(unlink("tempfile") < 0){
    std::cout<< "ulink file error"<<std::endl;
    return -1;
  }
  std::cout<<" file unlink"<<std::endl;
  sleep(15);
  std::cout<< "done"<< std::endl;
}
