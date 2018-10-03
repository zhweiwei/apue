#include "apue.h"

using std::cout;
using std::cin;
using std::endl;

static void charatatime(const char*);

int main(){
  pid_t pid;
  if((pid=fork() )<0){
  cout <<"fork error"<<endl;
  return -1;
  }else if(pid == 0){
  charatatime("output form child\n");
  }else{
  charatatime("output form parent\n");
  }
  exit(0);
}


static void
charatatime(const char *str){
  const char *ptr;
  int  c;
  setbuf(stdout,NULL);
  for(ptr = str;(c = *ptr++) !=0;){
  putc(c,stdout);
  }
}
