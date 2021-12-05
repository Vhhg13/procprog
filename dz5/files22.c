#include <stdio.h>

_Bool in(char ch, char* vows){
  for(int i=0;vows[i]!=0;++i)
    if(vows[i]==ch) return 1;
  return 0;
}


int main(void){
  char* vowels="aeiouy";
  int letters[256];
  for(int i=0;i<256;++i)
    letters[i]=0;
  
  FILE* fp=fopen("file22.txt", "r");
  
  for(char ch=fgetc(fp);ch!=EOF;ch=fgetc(fp)){
    if(in(ch, vowels))
      letters[ch]++;
  }
  int min=99999;
  char minl=' ';
  for(int i=0;i<256;++i){
    if(letters[i]<min && letters[i]!=0){
      min=letters[i];
      minl=(char)i;
    }
  }
  if(minl==' '){
    printf("В файле нет гласных\n");
  }else{
    printf("%c\n", minl);
  }
  return 0;
}
