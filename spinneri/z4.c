#include <stdio.h>

_Bool coupe_free(int i, int occupied[54]){
  return !(occupied[i*4] || occupied[i*4+1] || occupied[i*4+2] || occupied[i*4+3] || occupied[54-(i*2)-1] || occupied[54-(i*2)-2]);
}

int main(void){
  int N;
  scanf("%d", &N);
  int occupied[54];
  for(int i=0;i<54;++i){
    occupied[i]=1;
  }
  int t;
  for(int i=0;i<N;++i){
    scanf("%d", &t);
    occupied[t-1]=0;
  }
  
  int mx=0;
  int mx0=0;
  for(int i=0;i<9;++i)
    if(!coupe_free(i, occupied)){
      if(mx0>mx) mx=mx0;
      mx0=0;
    }else ++mx0;
  
  printf("%d\n", mx);
  return 0;
}
