#include <stdio.h>

int word(int num, char buff[200], char outp[200]){
  int spaces=0;
  int i=0;
  for(;buff[i]!=0;++i){
    if(buff[i]==' ') ++spaces;
    if(spaces==num) break;
  }
  i+=(buff[i]==' ');
  int j;
  for(j=0;buff[i]!=0 && buff[i]!=' ' && buff[i]!='\n';++j){
    outp[j]=buff[i];
    ++i;
  }
  outp[j]=0;
}

int main(void){
  FILE* fp=fopen("file2.txt", "r");
  FILE* out=fopen("file2.out", "w");
  _Bool found=0;
  char buff[200];
  char outp[200];
  int nth_word=0;
  for(;;){
    if(feof(fp) && !found) break;
    if(feof(fp)){
      ++nth_word;
      fseek(fp, 0, SEEK_SET);
      found=0;
      fputc(10, out);
    }
    fgets(buff, 100, fp);
    word(nth_word, buff, outp);
    if(outp[0]!=0 && !feof(fp)){
      found=1;
      fprintf(out, "%s ", outp);
    }
  }
  return 0;
}
