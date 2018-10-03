#include "apue.h"
#include <cstdlib>
using std::endl;
using std::cout;
using std::cin;

int main(int argv,char *argc[]){
  for(int i =0;i <argv;i++){
    cout<<"argc["<<i<<"] : "<< argc[i]<<endl;
  }
exit(0);
}
