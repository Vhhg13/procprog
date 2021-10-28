#include <stdio.h>

int gcd(int a, int b){
  if(b==0)
    return a;
  else
    return gcd(b, a%b);
}

int main(void){
  int a, b;
  while(1){
    scanf("%d %d", &a, &b);
    printf("%d\n", gcd(a, b));
  }
  return 0;
}
