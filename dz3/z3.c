#include <stdio.h>

int main(void){
  FILE *fp=fopen("file.txt", "r");
  char ch=fgetc(fp);
  while(ch!=EOF){
    putchar(ch);
    ch=fgetc(fp);
  }
  fclose(fp);
  return 0;
}
