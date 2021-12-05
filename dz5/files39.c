#include <stdio.h>

int main(void){
  FILE *fp=fopen("file39.txt", "r");
  printf("Введите символ, количество вхождений которово хотите подсчитать\n");
  char chr=getchar();
  int res=0;
  for(char ch=fgetc(fp);ch!=EOF;ch=fgetc(fp))
    if(ch==chr) ++res;
  printf("%d\n", res);
  fclose(fp);
  return 0;
}
