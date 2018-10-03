#include "apue.h"

using std::cout;
using std::cin;
using std::endl;

int main(){
  time_t q;
  time_t t = time(&q);
  cout << t << endl;
}
