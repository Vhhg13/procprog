#include <stdio.h>

int main(void){
  int j,i;
  for(i=0;i<=13;++i){
    j=0;
    if(i<4)
      for(;j<12;++j)
	putchar('*');
    for(;j<40;++j)
      putchar('-');
    putchar(10);
  }
  return 0;
}
