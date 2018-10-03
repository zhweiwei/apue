#include "apue.h"

using std::endl;
using std::cout;
using std::cin;

int globvar = 6;
char buf[] =  "a write to stdcouti\n";

int main(){
  int var;
  pid_t pid;

  var =88;
  if(write(STDOUT_FILENO,buf,sizeof(buf)-1) != sizeof(buf)-1)
    cout << "write error"<<endl;
  cout << "before fork   ";

  if((pid = fork()) < 0)
      cout <<"fork error"<<endl;
  else if(pid == 0){
    globvar++;
    var++;
  }else{
    sleep(2);
  }

  cout<<"pid= "<<getpid() <<" glob = "<<globvar <<" var= "<<var<<endl;
  exit(0);
  
}
