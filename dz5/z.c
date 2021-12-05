#include <stdio.h>
#include <locale.h>
#define match_pas\
  for(int j=0;j<7;++j) fl&=buff[i++]==pascal[j]

int _strlen(char buff[200]){
  int i=0;
  for(i=0;buff[i]!=0;++i);
  return i;
}

_Bool includes_pascal(char buff[200]){
  int sl=_strlen(buff);
  if(sl<7) return 0;
  const char* pascal="Паскаль";
  int i=0;
  if(sl==7){
    _Bool fl;
    match_pas;
    return fl;
  }
  // паскаль0
  // 01234567
  for(;;){
    if(buff[i+7]==0 && buff[i]!='П') return 0;
    if(buff[i+7]==0){
      _Bool fl=1;
      match_pas;
      return fl;
    }
    if(buff[i]=='П'){
      _Bool fl;
      match_pas;
      if(fl==1) return 1;
    }
    i++;
  }
  return 0;
}

int main(void){
  char* locale=setlocale(LC_ALL, "");
  char buff[200];
  for(;;){
    scanf("%s", buff);
    printf("%d\n", includes_pascal(buff));
  }
  return 0;
}
