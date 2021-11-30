#include <time.h>
#include <stdio.h>
#include <stdlib.h>


int main(void){
  printf("Какие числа вы хотите получить?\n1)Большие\n2)Маленькие\n");
  int ans;
  scanf("%d", &ans);
  srand(time(NULL));
  int s=rand();
  long m, i, c;
  if(ans==2){
    m=37; c=64;
    for(int i=1;i<4;++i)
      s=(int)((m*s+i)%c);
    printf("%d\n", s);
  }else if(ans==1){
    m=25173; c=65537;
    for(int i=1;i<13849;++i)
      s=(int)((m*s+i)%c);
    printf("%d\n", s);
  }else
    printf("Такой вариант выбрать нельзя!\n");
  return 0;
}
