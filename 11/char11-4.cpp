#include "apue.h"
#include <string>

using std::endl; using std::cout; using std::cin;
using std::string;

struct foo{
  int a,b,c;
};
 foo f;
void printfoo(const string& s,foo* f){
cout << s << "  "<< f->a<<" "<<f->b<<" "<<f->c<<endl;
}

void*
thr1(void *arg){
    f={1,2,3};
  printfoo("thread1 ",&f);
  pthread_exit(static_cast<void*>(&f));
}

void *
thr2(void *arg){
cout<<"thread2 :"<<pthread_self()<<endl;
pthread_exit((void*)0);
}

int main(){
  int err;
  pthread_t th1,th2;
  void *fp;

  err = pthread_create(&th1,NULL,thr1,NULL);
  if(err != 0)
    cout <<"pthread_create 1 error"<<endl;
  err = pthread_join(th1,&fp);
  if(err !=0)
    cout <<"pthread_join 1 error"<<endl;
  sleep(1);
  cout <<"parent start 2 thread"<<endl;
  err = pthread_create(&th2,NULL,thr2,NULL);
  if(err != 0)
    cout <<"pthread_create 2 error"<<endl;
  sleep(1);
  printfoo("parent foo",static_cast<foo*>(fp));
  exit(0);
  
}
