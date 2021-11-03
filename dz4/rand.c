#include <stdio.h>
#define s0 0

int s(int m, int i, int c){
  if(i==0) return s0;
  return (m*s(m, i-1, c)+i)%c;
}

int main(void){
  for(int i=1;i<10;++i)
    printf("%d) %d\n", i, s(37, i, 64));
  return 0;
}
