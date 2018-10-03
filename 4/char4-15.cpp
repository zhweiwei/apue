#include "apue.h"

int main(){
  if(link("tempfile","tempfile1")< 0){
    std::cout << "link file error"<< std::endl;
    return -1;
  }
  std::cout<<"link file ok" << std::endl;
}
