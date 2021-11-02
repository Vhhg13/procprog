#include <stdio.h>

int main(void){
  FILE *fp=fopen("file2.txt", "r");
  
  fclose(fp);
  return 0;
}
