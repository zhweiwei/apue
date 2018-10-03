#include "apue.h"
#define RWRWRW (S_IRUSR|S_IWUSR|S_IRGRP|S_IWGRP|S_IROTH|S_IWOTH)

int main(){
  umask(0);
  if(creat("f00",RWRWRW)< 0){
    std::cout << "create f00 file error"<< std::endl;
    return -1;
  }else{
    umask(S_IRGRP|S_IWGRP|S_IROTH|S_IWOTH);
  }
  if(creat("f11",RWRWRW) <0){
    std::cout << "create f11  file error" << std::endl;
    return -1;
  }
}
