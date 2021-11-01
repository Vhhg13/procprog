#include <stdio.h>
#include <math.h>

float fun(float s, float r, float n){
  float x=pow(r+1, n);
  return s*r*x/12/(x-1);
}

int main(void){
  float S, n, m;
  printf("Введите S, n, m\n");
  scanf("%f %f %f", &S, &n, &m);

  
  if(S<0 || m<0)
    printf("S и m не могут быть отрицательными\n");
  if(n<=0)
    printf("Нет решений (n<=0)\n");
  else if(S==0 && m==0)
    printf("Бесконечность решений (S=m=0)\n");
  else if(S==0 && m!=0)
    printf("Решений нет (s=0, m!=0)\n");
  else if(S!=0 && m==0)
    printf("Нет решений\n");
  else if(12*m*n==S)
    printf("p=0%%\n");
  else{
    float r;
    for(r=-1; (m > fun(S, r, n)) && (r<=1); r+=0.0001);
    if(m > fun(S, r, n))
      printf("Нет решений\n");
    else
      printf("p=%f\n", r*100);
  }
  return 0;
}
