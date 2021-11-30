#include <stdio.h>
#include <stdlib.h>

int main(void){
  FILE* fp=fopen("bna.txt", "r");
  char buff[100];
  scanf("%s", buff);
  
  fclose(fp);
  return 0;
}
