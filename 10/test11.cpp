#include <signal.h>
#include <iostream>

using std::endl; using std::cout; using std::cin;using std::string;

int
main()
{
  cout<<SIG_BLOCK<<endl;
  cout<<SIG_UNBLOCK<<endl;
  cout<<SIG_SETMASK<<endl;
}
