#include <stdio.h>
#include <math.h>

int main(void){
  float x, a;
  printf("Введите а и х\n");
  scanf("%f %f", &a, &x);
  
  if(x==0){
    printf("w не определена при х=0\n");
    return 1;
  }

  
  if(fabsf(x)<1){
    printf("%g\n", a*log(fabsf(x)));
    return 0;
  }
  float tmp=a-x*x;
  if(tmp>=0){
    printf("%g\n", sqrt(tmp));
  }else{
    printf("w не определена при таких а и х\n");
    return 1;
  }
  return 0;
}
