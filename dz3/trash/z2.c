#include <stdio.h>
#include <math.h>

int main(void){
  double S, p, n, m;

  printf("Введите S: ");
  scanf("%lf", &S);
  printf("Введите n: ");
  scanf("%lf", &n);
  printf("Введите m: ");
  scanf("%lf", &m);

  
  double sum=0;	// Для нахождения
  int num=0;	// среднего значения

  double r, r_plus_1, znam, m0;
  for(double p=-100;p<=100;p+=0.001){
    r=p/100.0;
    
    r_plus_1=pow(1+r, n);
    znam=12*(r_plus_1-1);
    
    if(znam==0) continue;
    
    m0=S*r*r_plus_1/znam;

    if(fabsf(m0-m)<=1){
      num++;
      sum+=p;
    }
  }

  if(n==0)
    printf("Нет решений (n=0)\n");
  else if(S==0 && m==0)
    printf("Бесконечность решений (S=m=0)\n");
  else if(S==0 && m!=0)
    printf("Решений нет (s=0, m!=0)\n");
  else if(S!=0 && m==0)
    printf("Нет решений\n");
    //    printf("p=0%% (s!=0, m=0)\n");
  else if(12*m*n==S)
    printf("p=0%%\n");
  else if(num!=0)
    printf("p=%.4lf%%\n", sum/(double)num);
  else
    printf("Нет решений %f\n", num);
  //  printf("%d\n", num);
  return 0;
}
