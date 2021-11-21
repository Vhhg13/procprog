#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define ERROR(str) return printf(str);
#define to_ch(num) (char)((num)+48)

int order(int num, int base){
  if(num==0) return 0;
  return 1+order(num/base, base);
}

char* convert(int num, int base, char *dest){
  int number=num;
  int ord= num==0 ? 1 : order(num, base);
  dest[ord]=0;
  for(int i=ord-1;i>=0;--i){
    dest[i]=to_ch(number%base);
    number/=base;
  }
  return dest;
}

int main(void){
  
  printf("Введите количество элементов массива:\n");
  int n;
  scanf("%d", &n);
  if(n<=0)
    ERROR("Количество может быть только натуральным числом\n");
  


  printf("Введите элементы массива\n");
  int F[n];
  for(int j=0;j<n;++j){
    char buff[200];
    scanf("%s", buff);
    int i;
    for(i=0;buff[i]!=0;++i)
      if(buff[i]!='1' && buff[i]!='0')
	ERROR("Вы ввели не двоичное число\n");
    int exp=0, num=0;
    for(--i;i>=0;--i)
      num+=(buff[i]-48)*pow(2, exp++);
    F[j]=num;
  }
  
  printf("Введите основание, в которое надо перевести числа\n");
  int base;
  scanf("%d", &base);
  if(base<3 || base>6)
    ERROR("Такое основание выбирать нечестно\n");

  char * arr[n]; //Результирующий массив с переведёнными числами
  char *ptr;
  int ord;
  for(int i=0;i<n;++i){
    ord = F[i]==0 ? 1 : order(F[i], base);
    ptr = (char*)malloc((ord+1)*sizeof(char));
    arr[i] = convert(F[i], base, ptr);
  }

  for(int i=0;i<n;++i)
    printf("%s\n", arr[i]);

  return 0;
}
