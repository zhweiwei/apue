extern char **environ;

pthread_mutex_t en_mutex;

static pthread_once_t init_done = PTHREAD_ONCE_INIT;

static void
thread_init(void){
  pthread_mutexattr_t attr;
  
  pthread_mutexattr_init(&attr);
  pthread_mutexattr_settye(&attr,PTHREAD_MUTEX_RECURSIVE);
  pthread_mutex_init(&en_mutex,&attr);
  pthread_mutexattr_destroy(&attr);
}

int 
getenv_t(const string& name,string& buf,int buflen){
  int i,len,olen;

  pthread_once(&init_once,thread_init);
  len = name.

}
