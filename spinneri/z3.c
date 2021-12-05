#include <stdio.h>

int main(void){
  int N, M;
  scanf("%d %d", &N, &M);
  int res=0;
  int ny, nx;
  for(int x=0;x<N;++x)
    for(int y=0;y<M;++y){
      nx=N-x;
      ny=M-y;
      res+=ny*nx;
    }
  printf("%d\n", res);
}
