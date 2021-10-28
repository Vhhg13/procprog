#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 30

char lower(char ch){
  if(65<=ch && ch<=90)
    return ch+32;
  return ch;
}

void bubblesort(char seq[31]);
//char includes(char a[31], char ch);

int main(void){

  char a[31];
  scanf("%s", a);
  printf("Исходная строка:\n%s\n", a);
  bubblesort(a);
  printf("\nРезультирующая строка:\n%s\n", a);

  return 0;
}






void bubblesort(char *seq){
  for(int c=0;seq[c+1]!='\0';c++)
    for(int d=0;seq[d+1]!='\0';d++)
      if(lower(seq[d])>lower(seq[d+1]))
	seq[d]=seq[d]+seq[d+1]-(seq[d+1]=seq[d]);
}

/* char includes(char a[31], char ch){ */
/*   for(int i=0;i<30;i++) */
/*     if(a[i]==ch) return 1; */
/*   return 0; */
/* } */
