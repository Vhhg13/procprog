#include <stdio.h>
#include <stdlib.h>

int main(void){
  float M, N, B, S;
  printf("Введите M, N, B, S\n");
  scanf("%f %f %f %f", &M, &N, &B, &S);
  if(N<=0) printf("N может быть только положительным числом\n");
  if(abs(B)!=1) printf("B может быть только 1 или -1\n");
  
  if(N>0 && abs(B)==1){
    while(N>0){
      printf("%g ", M);
      M+=B*S;
      N--;
    }
    printf("\n");
  }
  return 0;
}
