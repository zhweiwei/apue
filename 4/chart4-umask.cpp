#include "apue.h"

int main(){
  umask(777);
  if(creat("umask",O_RDWR)< -1){
  std::cout<<"create file error"<<std::endl;
  return -1;
  }
  std::cout<<"create file successful"<< std::endl;
  if(open("umask",O_RDONLY)< 0){
    std::cout<< "open file error"<<std::endl;
    return -1;
  }else{
    std::cout<<"open file successful"<<std::endl;
  }

} 
