#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define tolerance 0.1

_Bool eq(double s, double y){
  return fabs(s-y)<=tolerance;
}

double fun(double x){
  return sin(0.5*x);
}

int main(void){
  for(double y=15;y>-15;--y){
    if(y==0)
      for(int i=0;i<800;++i)
	putchar('=');
    else
      for(double x=-400;x<400;++x)
	if(x==0 || x==1)
	  putchar('#');
	else
	  putchar(eq(fun(x/10),y/15) ? '*' : ' ');
    printf("\n");
  }
  return 0;
}
