#include "apue.h"

/*
 *判断write与seek关系
 * 
 */

int main(){
int fd = creat("test.1",O_RDWR);
  if(fd == -1){
    std::cout<< "创建test1失败" << std::endl;
    return -1;
  }
  const char *a = "sdhaaas";
  std::cout <<"a = " <<  sizeof(a)<< std::endl;
  off_t a1 = write(fd,a,sizeof(a));
  std::cout << "a1 =  " << a1 << std::endl;

  char b[100]={'1','2'};
  std::cout <<"a = " <<  sizeof(b)<< std::endl;
  off_t b1 = write(fd,b,sizeof(b));
  std::cout << "b1 =  " << b1 << std::endl;
  
}
