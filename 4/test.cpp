#include "apue.h"
#include <string>

using std::string;
using std::cout;
using std::cin;

int main(){
  struct stat st;
  string str;
  while(cin >> str){
    if(stat(str.c_str(),&st) < 0){
    cout << "stat file error" << std::endl;
    return -1;
    }
    cout << "stat file successful"<<std::endl;
  }
}
