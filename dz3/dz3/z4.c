#include <stdio.h>

int main(void){
  FILE *fp=fopen("file.txt", "r");
  char prev;
  for(char ch=fgetc(fp);ch!=EOF;ch=fgetc(fp)){
    if(48<=ch && ch<=57)
      putchar(ch);
    else if(ch==10)
      putchar(10);
    else if(48<=prev && prev<=75)
      putchar(' ');
    prev=ch;
  }
  fclose(fp);
  return 0;
}
