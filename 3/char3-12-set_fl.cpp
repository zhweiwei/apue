#include "apue.h"

void set_fl(int fd,int flags){
  int val;
  if((val =fcntl(fd,F_GETFL,0)) < 0){
    std::cout<< "fcntl f_getfl error "<<std::endl;
    exit(-1);
  }
  val |= flags;	
  if(fcntl(fd,F_SETFL,val) < 0){
    std::cout<< "fcntl f_setfl error "<<std::endl;
    exit(-1);
  }

}

void clr_fl(int fd,int flags){
  int val;
  if((val =fcntl(fd,F_GETFL,0)) < 0){
    std::cout<< "fcntl f_getfl error "<<std::endl;
    exit(-1);
  }
  val &= ~flags;	
  if(fcntl(fd,F_SETFL,val) < 0){
    std::cout<< "fcntl f_setfl error "<<std::endl;
    exit(-1);
  }
}
