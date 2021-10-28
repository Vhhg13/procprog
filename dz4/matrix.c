#include <stdio.h>

int main(void){
  float A[3][4]={
    {5, 2, 0, 10},
    {3, 5, 2, 5},
    {20, 0 ,0, 0}};
  float B[4][2]={
    {1.2, 0.5},
    {2.8, 0.4},
    {5.0, 1.0},
    {2.0, 1.5}};
  float C[3][2];
  float res;
  for(int i=0;i<3;++i)
    for(int j=0;j<2;++j){
      res=0;
      for(int k=0;k<4;++k)
	res+=A[i][k]*B[k][j];
      C[i][j]=res;
    }
  
  for(int i=0;i<3;++i){
    for(int j=0;j<2;++j)
      printf("%.1f ", C[i][j]);
    putchar(10);
  }

  

  
  return 0;
}
