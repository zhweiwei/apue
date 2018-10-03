#include "apue.h"


using std::cout;
using std::cin;
using std::endl;

#define TOK_ADD	5
jmp_buf jmfbuffer;
void cmd_add();
int main(){
  if(setjmp(jmfbuffer) != 0){
    cout <<"this is jmpbuffer form if"<<endl;
    return -1;
  }
  cout <<"next call function"<<endl;
  cmd_add();
  cout<<" call function is ok"<<endl;
  return 0;
}

void cmd_add(){
  longjmp(jmfbuffer,1);
}
