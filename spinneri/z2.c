#include <stdio.h>

int main(void){
  printf("Введите количество лопастей: ");
  int m;
  scanf("%d", &m);
  int k4=m/4;
  int m4=m%4;
  while(m4%3!=0){
    --k4;
    m4+=4;
  }
  int k3=m4/3;
  if(m<0)
    printf("Отрицательного числа лопастей не может быть\n");
  else if(k3>=0 && k4>=0)
    printf("%d\n%d\n", k3, k4);
  else
    printf("0\n0\n");
  return 0;
}
