#include <vector>
#include <iostream>

using namespace std;

int main(){
  int a[10] ={1,2,3,4,5,5};
  vector<int> b(a,a+10);
  vector<int> c = b;
  b.clear();
  b.swap(c);
  cout<< "c = " <<c.size()<<endl;
}
