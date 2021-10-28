#include <stdio.h>

float y(float x){
  return (x*x-2*x+2)/(x-1);
}

int main(void){
  printf("x\ty\n");
  for(float x=-4;x<=4;x+=0.5){ //Сдлеть через while
    if(x==1) continue;
    printf("%g\t%g\n", x, y(x));
  }
  return 0;
}
