#include <stdio.h>
#include <math.h>

int main(void){
  printf("Введите x, y, b\n");
  float x, y, b;
  scanf("%f %f %f", &x, &y, &b);
  
  if( (b-y<=0) || (b-x<0) ){
    printf("Функция не определена при таких значениях x, y и b\n");
    return 1;
  }

  printf("z=%f\n", log(b-y)*sqrt(b-x));
  return 0;
}
