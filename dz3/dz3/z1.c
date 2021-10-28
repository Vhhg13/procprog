#include <stdio.h>
#include <math.h>

int main(void){
  float S, p, n;
  printf("Введите S: ");
  scanf("%f", &S);
  printf("Введите p: ");
  scanf("%f", &p);
  printf("Введите n: ");
  scanf("%f", &n);

  if(S<0 || n<0)
    printf("S и n не могут быть отрицательными\n");
  else if(p<-100 || 100<p)
    printf("p может принимать значения только в [-100; 100]\n");
  else if(S==0)
    printf("m=0\n");
  else if(n==0)
    printf("n не может быть равна 0\n");
  else if(p==0)
    printf("m=%g\n", (float)S/12/n);
  else{
    float r=p/100;
    float r_plus_1=pow(1+r, n);
    float znam=12*(r_plus_1-1);

    printf("m = %g\n", S*r*r_plus_1/znam);
  }

  return 0;
}
