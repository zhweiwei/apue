#ifdef __cplusplus
extern "C" {
#endif

#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <aio.h>
#include <strings.h>
#include <errno.h>

#ifdef __cplusplus
}
#endif

#include <iostream>

using std::endl; using std::cout; using std::cin;using std::string;

int main(){
  int fd,ret;
  char buf[64];
  
  struct aiocb my_aiocb;

  bzero((char*)&my_aiocb,sizeof(struct aiocb));

  my_aiocb.aio_buf = buf;
  my_aiocb.aio_fildes = STDIN_FILENO;
  my_aiocb.aio_nbytes = 54;
  my_aiocb.aio_offset = 0;

  ret = aio_read(&my_aiocb);
  if(ret < 0) cout<<" aio_read "<<endl;

  while(aio_error(&my_aiocb) == EINPROGRESS){
    write(STDOUT_FILENO,  ".",1);
    sleep(1);
  }

  cout << endl<<"content: "<<buf<<endl;
}
