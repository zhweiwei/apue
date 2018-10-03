#include "apue.h"

struct foo{
  int f_count;
  pthread_mutex_t f_lock;
  int f_id;
  foo(int id){
    f_count = 1;
    f_id =id;
    pthread_mutex_init(&f_lock,NULL);
  }
};

foo* 
foo_alloc(int id){
  foo *f;
  f = new foo(id);

  return f;
}

void 
foo_hold(foo *fp){
  pthread_mutex_lock(&fp->f_lock);
  fp->f_count++;
  pthread_mutex_unlock(&fp->f_lock);
}

void foo_rele(foo *fp){
  pthread_mutex_lock(&fp->f_lock);
  if(--fp->f_count == 0){
    pthread_mutex_unlock(&fp->f_lock);
    delete fp;
  }else{
    pthread_mutex_unlock(&fp->f_lock);
  }
  
}
