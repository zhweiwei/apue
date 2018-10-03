#include "apue.h"

using std::endl; using std::cout; using std::cin;using std::string;

int
 main()
{
  time_t tim = time(NULL);
  struct tm* tmp = gmtime(&tim);
  cout<<tmp->tm_sec<<" "<<tmp->tm_min<<" "<<tmp->tm_hour<<" "<<tmp->tm_mday<<" "<<tmp->tm_mon+1<<" "<<tmp->tm_year+1900<<endl;
  tmp = localtime(&tim);
  cout<<tmp->tm_sec<<" "<<tmp->tm_min<<" "<<tmp->tm_hour<<" "<<tmp->tm_mday<<" "<<tmp->tm_mon+1<<" "<<tmp->tm_year+1900<<endl;
}
