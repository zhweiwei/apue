#include "apue.h"

#define MAXSTRING 4096

static char envbuf[MAXSTRING];

extern char **environ;

char *
getenv(const char * name){
  int i ,len;
  len = strlen(name);
  for(i = 0;environ[i] != NULL;i++){
    if(strncmp(name,environ[i],len) == 0&& environ[i][len] == '='){
      strncpy(envbuf,&environ[i][len+1],MAXSTRING);
      return envbuf;
    }
  }
}
