#include "apue.h"

int main(){
  std::string str;
  while(std::cin >> str){
    if(remove(str.c_str())< 0 ){
      std::cout<<str<<"remove file error"<<std::endl;
      return -1;
    }
    std::cout<<"remove file ok"<<std::endl;
  }
}
