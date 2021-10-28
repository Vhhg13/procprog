#include <stdio.h>

#define error(str)				\
  printf(str);					\
  return 0

char upper(char ch){
  return ch-((97<=ch && ch<=122) ? 32 : 0);
}

int to_decimal(char num[100], int from_base){
  int res=0;
  char ch;
  for(int i=0;num[i]!=0;i++){
    ch=upper(num[i]);
    if(65<=ch && ch<65+from_base-10)
      res=res*from_base+(ch-65+10);
    else if(48<=ch && ch<48+from_base)
      res=res*from_base+(ch-48);
    else
      return -1;
  }
  return res;
}

int main(void){
  printf("Введите исходное число: ");
  char inp[100];
  scanf("%s", inp);

  printf("Введите исходное основание: ");
  int base0;
  scanf("%d", &base0);

  printf("Введите новое основание: ");
  int base1;
  scanf("%d", &base1);
  if(base1*base0==0){
    error("Основание системы счисления не может быть равно 0\n");
  }

  int number=to_decimal(inp, base0);
  if(number==0){
    error("0\n");
  }
  if(number==-1){
    error("В записи исходного числа сожержатся невозвожные символы\n");
  }
  char outp[100];
  int i;
  for(i=0;number>0;i++){
    int ch=number%base1;
    if(ch>=10)
      outp[i]=(char)ch-10+65;
    else
      outp[i]=(char)ch+48;
    number=number/base1;
  }

  
  for(i--;i>=0;i--)
    putchar(outp[i]);
  putchar(10);

  return 0;
}
