#include "apue.h"

int main(int argv,char *argc[]){
  if(argv <2 )
    return -1;
  struct stat st;
  for(int i =1; i != argv;i++){
    if(stat(argc[i],&st)< 0){
      std::cout << argc[i] << "file open error"<<std::endl;
      return -1;
    }
    std::cout<<"st_mode " << st.st_mode<<std::endl
	    << "st_inode "<< st.st_ino<<std::endl
	    << " st_size "<<st.st_size<< std::endl
	    <<"st_dev "<<st.st_dev<<std::endl
	    <<"st_rdev "<<st.st_rdev<<std::endl
	    <<"st_nlink "<<st.st_nlink<<std::endl
	    <<"st_blocks "<<st.st_blocks<< std::endl
	    <<"st_blksize "<<st.st_blksize<<std::endl;
  }

}
