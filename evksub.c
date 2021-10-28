#include <stdio.h>

int gcd(int a0, int b0){
  int a=a0, b=b0;
  while(a!=b){
    if(a>b)
      a-=b;
    else
      b-=a;
  }
  return a;
}

int main(void){
  int a, b;
  while(1){
    scanf("%d %d", &a, &b);
    printf("%d\n", gcd(a, b));
  }
  return 0;
}
