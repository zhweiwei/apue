#include <unistd.h>
#include <sys/select.h>

#include <iostream>
using std::endl; using std::cout; using std::cin;using std::string;

void printset(const fd_set *st){
  int i = 0;
  for(i = 0;i < 16;++i){
    if(FD_ISSET(i,st))
      cout<< "1";
    else
      cout<<"0";
  
    cout<<" ";
  }
  cout<<endl;
}

int main(){
  int i;
  fd_set st;
  cout<<"uninitial"<<endl;
  
  printset(&st);

  cout<<"zeros"<<endl;
  FD_ZERO(&st);
  printset(&st);
  
  cout<<"set odd"<<endl;
  for(i = 0;i < 16;++i){
    if(i%2){
    FD_SET(i,&st);
    }
  }
  printset(&st);


}
