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
  
  my_aiocb.aio_lio_opcode = LIO_READ;

   struct aiocb * aio_list[5] = {NULL};
  
  aio_list[3] = &my_aiocb;
  
  ret = lio_listio(LIO_NOWAIT,aio_list,5,NULL);

  while(aio_error(&my_aiocb) == EINPROGRESS){
    write(STDOUT_FILENO,  ".",1);
    sleep(1);
  }
  
  ret = aio_return (&my_aiocb);
  cout <<"ret "<<ret <<endl;
  cout << endl<<"content: "<<buf<<endl;
}
