#include "apue.h"
#include <string>
#include <iostream>

using std::endl; using std::cout; using std::cin;using std::string;

class fileopen{
  int size;
  string route;
  int computesize(const string&)const;
  public:
  explicit  fileopen(const string& t):route(t),size(0){
  }
  int getsize()const{
    return computesize(route);
  }
};

int
fileopen::computesize(const string& d)const{
  struct stat st;
  DIR* dr;
  int size = 0;
   string tmp;
  lstat(d.c_str(),&st);
  if(S_ISDIR(st.st_mode)){
    dr = opendir(d.c_str());
    struct dirent* drt;
    while((drt = readdir(dr))!= NULL){
    if(strcmp(drt->d_name,".") == 0 || strcmp(drt->d_name,"..")== 0) continue;
      tmp = d+"/"+drt->d_name;
     size += computesize(tmp);
    }
  }else{
    size += st.st_size;
  }
  return size;
}

int main(int argc,char* argv[]){
  if(argc < 2){
    cout<<"have two"<<endl;
    return 1;
  }
  fileopen a(argv[1]);
  cout << " size "<< a.getsize()<<endl;
}
