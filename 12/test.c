#include <stdio.h>
#include <stdlib.h>

int main(){
 int i = system("ssh 192.168.21.22 rm -rf /var/cos/cvm/data/sys/test");
  printf("%d",i);
}
