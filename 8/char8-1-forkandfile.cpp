#include "apue.h"

using std::endl;
using std::cout;
using std::cin;

int globvar = 6;
char buf[] =  "a write to stdcouti\n";

int main(){
  int var;
  pid_t pid;
  FILE *p1;
  FILE *p2;
  var =88;
  p1 = fopen("1.txt","a+b");
  fseek(p1,100,SEEK_SET);
  if(write(STDOUT_FILENO,buf,sizeof(buf)-1) != sizeof(buf)-1)
    cout << "write error"<<endl;
  cout << "before fork   ";

  if((pid = fork()) < 0)
      cout <<"fork error"<<endl;
  else if(pid == 0){
    globvar++;
    var++;
  fseek(p1,100,SEEK_CUR);
  if(fwrite(buf,sizeof(buf),1,p1) < 1)
    cout<< "fork1 fwrite error"<<endl;
  p2 = fopen("2.txt","a+b");
  fseek(p2,1000,SEEK_SET);
  }else{
    sleep(2);
  p2 = fopen("2.txt","a+b");
  fseek(p2,10,SEEK_SET);
  fseek(p1,10,SEEK_CUR);
  }

  cout<<"ppid = "<<getppid()<<"pid= "<<getpid() <<" glob = "<<globvar <<" var= "<<var << "  p1 ="<<ftell(p1)<<"  p2 = "<<ftell(p2)<<endl;
while(fread(buf,sizeof(buf),1,p1) < 0)
  cout << buf<<endl;
  exit(0);
  
}
