

void wlock(int fd,int start,int len){
  struct flock flk;
  
  flk.type = F_WRLCK;
  flk.l_whence = SEEK_SET;
  flk.start = start;
  flk.l_len = len;
  
  fcntl(fd,F_SETLKW,&flk);
}

