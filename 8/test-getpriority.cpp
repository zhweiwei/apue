#include <unistd.h>
#include <sys/resource.h>

#include <iostream>

using std::endl; using std::cout; using std::cin;using std::string;

int
main()
{
  cout <<getpriority(PRIO_USER,getuid())<<endl;
}
