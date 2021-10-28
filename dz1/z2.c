#include <stdio.h>
#include <stdlib.h>

int main(void){
  float a, b;
  scanf("%g %g", &a, &b);
  float sum=a+b;
  float diff=abs(a-b);
  float product=a*b;
  printf("Сумма: %g\nРазность: %g\nПроизведение: %g\n", sum, diff, product);

  if(a==0 && b==0){
    (void)0;
  }else if(a==0 || b==0){
    printf("Частное: 0\n");
  }else{
    if(a>b)
      printf("Частное: %g", a/b);
    else
      printf("Частное: %g", b/a);
    printf("\n");
  }

  return 0;
}
