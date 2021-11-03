#include <stdio.h>
// C_i == Количество продавцов
#define C_i 3
#define C_j 2

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
  float C[C_i][C_j];
  float res;
  
  for(int i=0;i<C_i;++i)
    for(int j=0;j<C_j;++j){
      res=0;
      for(int k=0;k<4;++k)
	res+=A[i][k]*B[k][j];
      C[i][j]=res;
    }
  
  // 1
  float mx=0, mn=1000;
  int ind_min, ind_max;
  for(int i=0;i<C_i;++i){
    if(C[i][0]<mn){
      mn=C[i][0];
      ind_min=i;
    }
    if(C[i][0]>mx){
      mx=C[i][0];
      ind_max=i;
    }
  }
  printf("1) min: %d, max: %d\n", ind_min+1, ind_max+1);


  
  // 2
  mx=0; mn=1000;
  for(int i=0;i<C_i;++i){
    if(C[i][1]<mn){
      mn=C[i][1];
      ind_min=i;
    }
    if(C[i][1]>mx){
      mx=C[i][1];
      ind_max=i;
    }
  }
  printf("2) min: %d, max: %d\n", ind_min+1, ind_max+1);


  
  // 3
  res=0;
  for(int i=0;i<C_i;++i)
    res+=C[i][0];
  printf("3) %.1f\n", res);


  
  // 4
  res=0;
  for(int i=0;i<C_i;++i)
    res+=C[i][1];
  printf("4) %.1f\n", res);


  
  // 5
  res=0;
  for(int i=0;i<C_i;++i)
    for(int j=0;j<C_j;++j)
      res+=C[i][j];
  printf("5) %.1f\n", res);
  

  
  return 0;
}
