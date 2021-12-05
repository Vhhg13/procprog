#include <stdio.h>

_Bool aum(long long int number){
  long long int n, sq;
  n=number;
  sq=number*number;
  while(sq!=0 && n!=0){
    if(sq%10!=n%10) return 0;
    sq/=10;
    n/=10;
  }
  return 1;
}

int main(void){
  printf("Введите границы диапазона: ");
  long long int m, n;
  scanf("%ld %ld", &m, &n);
  for(long long int i=m; i<=n;++i)
    if(aum(i))
      printf("%d ", i);
  putchar(10);
  return 0;
}
