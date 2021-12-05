#include <stdio.h>
#include <math.h>

typedef struct interval{
  int from;
  int to;
}interval;

int middle(interval inv){
  return (inv.to+inv.from)/2;
}

void longest_free(int* arr, int size, interval* res){
  int beg=0, len=0;
  int beg0=0, len0=0;
  for(int i=0;i<size;++i){
    if(arr[i]!=0){
      len0=0;
      beg0=0;
    }else if(arr[i]==0){
      if(beg0==0) beg0=i;
      ++len0;
    }
    if(len0>len){
      len=len0;
      beg=beg0;
    }
  }
  res->from=beg;
  res->to=beg+len-1;
}

int main(void){
  int N, K;
  scanf("%d %d", &N, &K);
  if(K>N){
    printf("У вас не все ученики вместятся\n");
    return 0;
  }
  int arr[N+2];
  for(int i=0;i<N+2;arr[i++]=0);
  arr[0]=1;arr[N+1]=1;
  interval res;
  for(int i=1;i<=K;++i){
    longest_free(arr, N+2, &res);
    arr[middle(res)]=i;
  }
  for(int i=0;i<N+2;++i)
    printf("%d ", arr[i]);
  putchar(10);
  int left=(res.to-res.from)/2;
  int right=ceil((res.to-res.from)/(float)2);
  printf("%d %d\n", left, right);
  
  return 0;
}
