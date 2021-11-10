#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

#define to_ch(num) (char)((num)+48)

int order(int num, int base){
  if(num==0) return 0;
  return 1+order(num/base, base);
}

void convert(double num, int base, char res[100]){
  int entier=floor(num);
  double frac=num-entier;
  
  int ord=entier==0 ? 1 : order(entier, base);
  for(int i=ord-1;i>=0;--i){
    res[i]=to_ch(entier%base);
    entier/=base;
  }
  if(frac==0) return (void)(res[ord]=0);
  res[ord]='.';
  int i;
  for(i=ord+1;frac!=0;++i){
    int tmp=frac*(double)base;
    res[i]=to_ch(floor(tmp));
    frac=tmp-floor(tmp);
  }
  res[i]=0;
}

int main(void){
  printf("Введите количество элементов массива:\n");
  int n;
  scanf("%d", &n);
  
  printf("Введите элементы массива\n");
  double F[n];
  for(int i=0;i<n;++i)
    scanf("%lf", &F[i]);
  
  printf("Введите основание, в которое надо перевести числа\n");
  int base;
  scanf("%d", &base);

  if(base<3 || base>6){
    printf("Такое основание выбирать нечестно\n");
    return 0;
  }

  char * arr[n]; //Результирующий массив с переведёнными числами
  char res[100];
  char *ptr;
  int len;
  for(int i=0;i<n;++i){
    convert(fabs(F[i]), base, res);
    len=strlen(res)+(F[i]<0)+1;
    ptr=(char*)malloc(len*sizeof(char));
    if(F[i]<0) ptr[0]='-';
    for(int j=(int)(F[i]<0);j<len;++j)
      ptr[j]=res[j-(int)(F[i]<0)];
    arr[i]=ptr;
  }

  
  for(int i=0;i<n;++i)
    printf("%s\n", arr[i]);

  return 0;
}
