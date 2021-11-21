#include <stdio.h>

void swap(int* n1, int* n2){
  *n1+=*n2;
  *n2=*n1-*n2;
  *n1=*n1-*n2;
}

int factorial(int num){
  int res=1;
  for(int i=1;i<=num;++i)
    res*=i;
  return res;
}

typedef int shar;

_Bool in(shar sh, shar * shary){
  for(int i=0;shary[i]!=0;++i)
    if(sh==shary[i]) return 1;
  return 0;
}

_Bool aldif(shar *shary){
  if(shary[0]==0) return 1;
  return !in(shary[0], shary+1) && aldif(shary+1);
}

_Bool fun(shar* shary, int n){
  for(int i=0;i<n;++i)
    if(shary[i]==i+2) return 1;
  return 0;
}

void heaps(int k, shar* A, int* z, int n){
  if(k==1)
    *z+=fun(A, n);
  else{
    heaps(k-1, A, z, n);
    for(int i=0;i<k-1;++i){
      if(k%2==0)
	swap(&A[i], &A[k-1]);
      else
	swap(&A[0], &A[k-1]);
      heaps(k-1, A, z, n);
    }
  }
}

int main(void){
  int z=0, n=10;
  shar shary[n-1];
  shary[0]=1;
  for(int i=3;i<=n;++i)
    shary[i-2]=i;
  heaps(n-1, shary, &z, n-1);
  
    
  
  int result=factorial(n-1)+(n-1)*z;
  printf("z=%d\nresult=%d\n", z, result);
  return 0;
}
