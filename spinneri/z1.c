#include <stdio.h>

int main(void){
  int A, B, C, N;
  printf("Введите A, B, C\n");
  scanf("%d %d %d", &A, &B, &C);
  for(N=0;A+B*N<=C;++N);
  printf("%d\n", N-1);
  return 0;
}
