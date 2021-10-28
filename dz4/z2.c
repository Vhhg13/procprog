#include<stdio.h>

int sign(float x){
  if(x==0) return 0;
  if(x>0)  return 1;
  if(x<0)  return -1;
}

int main(void){
  float x;
  printf("Введите любое число\n");
  scanf("%f", &x);
  printf("sign(%f)=%d\n", x, sign(x));
  return 0;
}
// 3.1
// 3.2 100
// 3.4 
