#include <stdio.h>
#include <math.h>
// gcc z4.c -o z4 -lm

int linear(float b, float c);

int main(void){
  float a, b, c;
  scanf("%g %g %g", &a, &b, &c);
  if(a==0)
    return linear(b, c);
  float d=b*b-4*a*c;

  if(d<0){
    printf("Нет решений\n");
  }else if(d==0){
    float x=-b/2/a;
    if(x==0)
      printf("x=0\n");
    else
      printf("x=%g\n", x);
  }else{
    float x1=(-b+sqrt(d))/2/a;
    float x2=(-b-sqrt(d))/2/a;

    if(x1==0)
      printf("x1=0\n");
    else
      printf("x1=%g\n", x1);

    if(x2==0)
      printf("x2=0\n");
    else
      printf("x2=%g\n", x2);
  }

  
  return 0;
}

int linear(float b, float c){
  // Из Дз1 задания 3
  if(b==0){
    if(c==0)
      printf("Бесконечность решений\n");
    else
      printf("Нет решений\n");
  }else{
    float x=-c/b;
    if(x==0)
      printf("x=0\n");
    else
      printf("x=%g\n", x);
  }
  return 0;
}
