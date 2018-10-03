#include "apue.h"
/*
 *  
 *
 */

int main(){
  int i;
  struct stat buf;
  std::string ptr;
  while(std::cin >> ptr){
    if(lstat(ptr.c_str(),&buf) < 0){
      std::cout << ptr << " error"<< std::endl;
      continue;
    }
    if(S_ISREG(buf.st_mode))
      std::cout << ptr <<" is regular file "<<std::endl;
    else if(S_ISCHR(buf.st_mode))
      std::cout << ptr << " is charactor file "<< std::endl;
    else if(S_ISDIR(buf.st_mode))
      std::cout<< ptr << " is directory " << std::endl;
    else if(S_ISBLK(buf.st_mode))
      std::cout <<ptr << " is block file "<< std::endl;
    else if(S_ISFIFO(buf.st_mode))
      std::cout<< ptr << " is FIFO file "<< std::endl;
    else if(S_ISSOCK(buf.st_mode))
      std::cout << ptr << " is socket file "<< std::endl;
    else if(S_ISLNK(buf.st_mode)) 
      std::cout << ptr<< " id link file " << std::endl; 
  }
  
}
