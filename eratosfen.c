#include <stdio.h>

#define true 1
#define false 0

int main(void){
  printf("Введите верхнюю границу\n");
  int N;
  scanf("%d", &N);
  if(N<2){
    printf("Простых чисел меньших, чем 2 не существует\n");
    return 0;
  }
  
  _Bool arr[N+1];
  for(int i=0;i<=N;i++)
    arr[i]=true;

  arr[0]=false; arr[1]=false;
  

  for(int i=2;i<=N;i++){
    if(arr[i]!=true) continue;
    for(int j=i+i;j<=N;j+=i){
      arr[j]=false;
    }
  }

  
  for(int i=0;i<=N;i++)
    if(arr[i]) printf("%d ", i);
  putchar(10);
  return 0;
}
