#include "apue.h"

using std::cout;
using std::cin;
using std::endl;

int main(){
  if(chown("14",1000,1000)< 0){
    cout <<"chown error"<<endl;
    return -1;
  }   
  cout <<"chown is ok"<<endl;
}
