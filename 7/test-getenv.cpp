#include <cstdlib>
#include <iostream>
#include <string>

using std::string;
using std::endl;
using std::cout;
using std::cin;

int main(){
extern char **environ;
char  **p = environ;
for(;*p != NULL;p++)
  cout << *p <<endl;
cout<<getenv("PWD")<<endl;
}
