#include "apue.h"

using std::endl; 
using std::cout; 
using std::cin;

void ptr_times(clock_t,struct tms *,struct tms *);
void do_cmd(char *);

int main(int argc,char *argv[]){
  int i;
  setbuf(stdout,NULL);
  for(i = 1;i < argc;i++)
    do_cmd(argv[i]);

  exit(0);
}

void do_cmd(char *cmd){
  struct tms tmsstart,tmsend;
  clock_t start,end;
  int status;

  cout<<"commend "<<cmd<<endl;

  if((start = times(&tmsstart)) == -1)
    cout << "times error"<<endl;
    
  if((status = system(cmd)) < 0)
    cout << "system error"<<endl;

  if((end = times(&tmsend)) == -1)
    cout <<"times end error"<<endl;
  
  ptr_times(end - start,&tmsstart,&tmsend);
}

void ptr_times(clock_t real,struct tms *tmsstart,struct tms *tmsend){
  static long clktck = 0;
  if(clktck == 0)
    if((clktck = sysconf(_SC_CLK_TCK))< 0)
    cout << "sysconf error"<<endl;
  cout <<"real: "<<real/(double)clktck<<endl;
  cout <<"user: "<<(tmsend->tms_utime - tmsstart->tms_utime)/(double)clktck<<endl;
  cout <<"system: "<<(tmsend->tms_stime - tmsstart->tms_stime)/(double)clktck<<endl;
  cout <<"child: "<<(tmsend->tms_cutime - tmsstart->tms_cutime)/(double)clktck<<endl;
  cout <<"child system: "<<(tmsend->tms_cstime - tmsstart->tms_cstime)/(double)clktck<<endl;
}
