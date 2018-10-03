#include "apue.h"

using std::endl; using std::cout; using std::cin;using std::string;


void my_alrm(int value){
    cout <<"this is my_alrm"<<endl;
  }
int main(){
  if(signal(SIGALRM,my_alrm) == SIG_ERR){
    cout <<"signal error"<<endl;
    } 

alarm(1);
  pause();
}
