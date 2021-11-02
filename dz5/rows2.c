#include <stdio.h>
#include <math.h>

int fact(int n){
  int res=1;
  for(int i=1;i<=n;++i)
    res*=i;
  return res;
}

int main(void){
  int n;
  scanf("%d", &n);
  if(n<=0){
    printf("Такое число нельзя\n");
    return 0;
  }
  float res=0;
  int last=1;
  for(int i=0;i<n;++i){
    float tmp=0;
    int j=last;
    for(;j-last!=i+1;++j)
      tmp+=j;
    res+=fact(n-i)/sqrt(tmp);
    last=j;
  }
  printf("%f\n", res);
  return 0;
}
