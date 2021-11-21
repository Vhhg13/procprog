#include <stdio.h>

void swap(int* n1, int* n2){
  *n1+=*n2;
  *n2=*n1-*n2;
  *n1=*n1-*n2;
}

void heaps(int k, int* A){
  if(k==1)
    printf("%d %d %d\n", A[0], A[1], A[2]);
  else{
    heaps(k-1, A);
    for(int i=0;i<k-1;++i){
      if(k%2==0)
	swap(&A[i], &A[k-1]);
      else
	swap(&A[0], &A[k-1]);
      heaps(k-1, A);
    }
  }
}

int main(void){
  int A[3]={1, 2, 3};
  heaps(3, A);
  return 0;
}
