#include <stdio.h>

int main(void){
  FILE *fp=fopen("file39.txt", "r");
  for(char ch=fgetc(fp);ch!=EOF;ch=fgetc(fp)){
    
  }
  fclose(fp);
  return 0;
}
