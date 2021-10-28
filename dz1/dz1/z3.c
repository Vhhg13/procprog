#include <stdio.h>

int main(void){
  float b,c;
  scanf("%g %g", &b, &c);

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
