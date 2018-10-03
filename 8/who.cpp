#include "apue.h"

using std::endl; using std::cout; using std::cin;using std::string;\

int 
main()
{
  setuid(getuid());
  cout<<"uid "<<getuid()<<" euid "<<geteuid()<<endl;

}
