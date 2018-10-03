#include "apue.h"
#include <sys/wait.h>
#include <cstdlib>

using std::endl; using std::cout; using std::cin; 
using std::string;
using std::flush;
#define MAXLINE  4096
int 
main(){
  char line[MAXLINE];
  FILE *fin;
  string s;
  if((fin = popen("myucle","r")) == NULL){
    cout<<"popen error"<<endl;
  }
  for(;;){
    cout<<"prompt> "<<flush;
  if(fgets(line,MAXLINE,fin) == NULL)
    break;
  if(fputs(line,stdout) == EOF)
    cout<< "fputs error"<<endl;
  }

  if(pclose(fin) == -1)
    cout<<"fclose error"<<endl;

  exit(0);
  
}
