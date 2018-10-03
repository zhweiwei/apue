#include "apue.h"

using std::cout;
using std::cin;
using std::endl;

int main(){
  struct timespec q;
  time_t t = clock_gettime(CLOCK_REALTIME,&q);
  cout << t << endl;
  cout << q.tv_sec << endl;
  cout << q.tv_nsec << endl;
  t = clock_gettime(CLOCK_PROCESS_CPUTIME_ID,&q);
  cout << t << endl;
  cout << q.tv_sec << endl;
  cout << q.tv_nsec << endl;
}
