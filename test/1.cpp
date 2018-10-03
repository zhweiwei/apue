#include <iostream>
#include <vector>
#include <iterator>

using namespace std;
typedef struct {
  double a1;
  double b1;
  double v1;
  double a2;
  double b2;
  double v2;
}b;
int main(){
int a;
cin >> a;
  int i = 0;
  int x,y,tempx,tempy,count=0;
  b temp;
  vector<b> p;
  while(i < a){
    cin>> temp.a1 >>temp.b1 >>temp.v1 >>temp.a2>>temp.b2>>temp.v2;
    p.push_back(temp);
  i++;
  }
   int q = 0;
  while(q < a){
    for(x = 1;p[q].a1 * x < p[q].v1;x++){
      for(y = 1;(p[q].b1 * y +p[q].a1*x)< p[q].v1;y++){
        if((p[q].a1 * x + p[q].b1 * y) == p[q].v1){
	 if(( p[q].a2 * x + p[q].b2 * y) == p[q].v2){
	  tempx = x;
	  tempy = y;
	  count++;
	  if(count >1) break;
	    }
        }
      }
      if(count >1) break;
    }
  

  if(count == 1){
    cout<< tempx <<" "<<tempy<<endl;
  }else{
    cout<<"UNKNOWN"<<endl;
  }  
q++;
  count=0;
}
}
