#include <stdio.h>
#include <stdlib.h>

#define move(a, b) _move(towers, (a), (b))
#define top(ind) _top(towers, (ind))

int* _top(int **towers, int ind){
  int i;
  for(i=0;towers[ind][i]==0;++i);
  return &towers[ind][i];
}

void _move(int **towers, int from, int to){
  printf("|%d => %d|\n", from+1, to+1);
  int* top1=_top(towers, from);
  int* top2=_top(towers, to);
  //  printf("%d %d\n", *top1, *(top2+1));
  if(*top1>*top2) return (void)printf("Произошла попытка сделать плохо\n");
  *(top2-1)=*top1;
  *top1=0;
}

void hanoi(int **towers, int size, int from, int to, int intr){
  if(size==1){
    move(from, to);
    return;
  }
  hanoi(towers, size-1, from, intr, to);
  move(from, to);
  hanoi(towers, size-1, intr, to, from);
}

int main(void){
  int n;
  printf("Введите n\n");
  scanf("%d", &n);
  int *towers[3];
  towers[0]=(int*)calloc(n+1, sizeof(int));
  towers[1]=(int*)calloc(n+1, sizeof(int));
  towers[2]=(int*)calloc(n+1, sizeof(int));
  for(int i=0;i<n;++i){
    towers[0][i]=i+1;
    towers[1][i]=0;
    towers[2][i]=0;
  }
  for(int i=0;i<3;++i)
    towers[i][n]=100;

  hanoi(towers, n, 0, 2, 1);

  /* printf("---\n"); */
  /* for(int i=0;i<3;++i){ */
  /*   for(int j=0;j<n;++j) */
  /*     printf("%d ", towers[i][j]); */
  /*   putchar(10); */
  /* } */
  return 0;
}
