#include "apue.h"

int main(){
  if(rename("tempfile","f11")< 0){
    std::cout << "rename file error" <<std::endl;
    return -1;
  }
  std::cout <<"rename file ok"<<std::endl;
}
