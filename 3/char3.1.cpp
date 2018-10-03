#include "apue.h"

int main(){
  if(lseek(STDIN_FILENO,0,SEEK_CUR) == -1)
    std::cout<< "connot seek " << std::endl;
  else
    std::cout<< "can seek " << std::endl;
}
