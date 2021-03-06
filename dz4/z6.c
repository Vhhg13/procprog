#include <stdio.h>
#define MATCH(str, nm) if(match(num+i, str, ch)) return nm
#define upper(ch) ch-((97<=ch && ch<=122) ? 32 : 0)

int rom[256];

int ord(int num){
  if(num==0) return 0;
  return 1+ord(num/10);
}

int th(char * num){
  int res;
  for(res=0;num[res]=='M';++res);
  return (res>3) ? -1 : res;
}

_Bool match(char * num, char* pat, char ch[4]){
  if(pat[0]==0) return 0; 
  _Bool res=1; int i=0;
  for(;num[i]!=0 && pat[i]!=0;++i)
    res=res && num[i]==ch[pat[i]-48];
  if(num[i]==0 && pat[i]!=0) return 0;
  if(ord(rom[num[i]])>=ord(rom[ch[0]])) return 0;
  return res;
}

int count(char *num, char ch[4]){
  int i;
  for(i=0;ord(rom[num[i]])>=ord(rom[ch[2]]);++i);
  if(ord(rom[num[i]])<ord(rom[ch[0]])) return 0;
  MATCH("000", 3);      MATCH("00", 2);
  MATCH("01", 4);       MATCH("02", 9);
  MATCH("0", 1);        MATCH("1000", 8);
  MATCH("100", 7);      MATCH("10", 6);
  MATCH("1", 5);
  return -1;
}

int main(void){
  rom['I']=1; rom['V']=5;
  rom['X']=10; rom['L']=50;
  rom['C']=100; rom['D']=500;
  rom['M']=1000; rom[0]=0;
  char inp[200];
  printf("Введите римское число\n");
  scanf("%s", inp);

  for(int i=0;inp[i]!=0;++i)
    if(inp[i]=='M' || inp[i]=='D' || inp[i]=='C' || inp[i]=='L' || inp[i]=='X' || inp[i]=='V' || inp[i]=='I')
      inp[i]=upper(inp[i]);
    else
      return printf("Корявое число\n");

  int thousands=th(inp);
  int hundreds=count(inp, "CDM");
  int tens=count(inp, "XLC");
  int units=count(inp, "IVX");
  if(thousands<0 || hundreds<0 || tens<0 || units<0)
    printf("Корявое число\n");
  else
    printf("%d\n", thousands*1000+hundreds*100+tens*10+units);
  return 0;
}
