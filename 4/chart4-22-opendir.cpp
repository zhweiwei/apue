#include "apue.h"
#include <string>
#include <cstdlib>

using std::string;

struct stat st;
 DIR *dr;
struct dirent *dent;

class computeSize{
private:
  int size;
  string dir;
  bool isDir(const string& s)const;
  int compute(const string& s)const;
  const string connect(const string& a,const string& b)const;

public:
   computeSize(const string& b):dir(b){
    size = 0;
  }
  int  getSize()const;
// void getContent()const;
};

/*
 *isDir 用于判断传入的文件路径是否为目录
 */

const string computeSize::connect(const string& a,const string& b)const{
  return a+"/"+b;
}

bool computeSize::isDir(const string& s)const{
    if(stat(s.c_str(),&st) < 0){
      std::cout<<s<<" judge file error"<<std::endl;
      exit(-1);
    }
    return S_ISDIR(st.st_mode);
}

int  computeSize::getSize()const{
  return compute(dir);
}

int computeSize::compute(const string& dir)const{
  int size = 0;  //计算目录的大小
  if(!isDir(dir)){
  if(stat(dir.c_str(),&st) <0){
    std::cout<< dir<<" stat file error"<<std::endl;
    exit(-1);
    }else{
    size += st.st_size;
    }    
  }else{
    dr = opendir(dir.c_str());
    if(dr < 0){
    std::cout <<dir <<" opendir is error"<<std::endl;
    exit(-1);
    }
    while(dent = readdir(dr)){
      std::cout<< dent->d_name<< std::endl;
      if(strcmp(dent->d_name,".") == 0 || strcmp(dent->d_name,"..") == 0) // 判断是否为本目录和父目录
	  continue;
      const string temp = connect(dir,dent->d_name);
      std::cout << temp<< std::endl;
    if(!isDir(temp)){
      if(stat(temp.c_str(),&st) <0){
	std::cout<< dir<<" stat file error"<<std::endl;
	exit(-1);
      }else{
	size += st.st_size;
    }    
      }else{
      size += compute(temp);
      }
    }
  }
  return size;
}

int main(){
string str;
computeSize *p;
while(std::cin >> str){
  p = new computeSize(str);
  std::cout<< p->getSize()<< std::endl;
  delete p;
  p = NULL;
  }
}

