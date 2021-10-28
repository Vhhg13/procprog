#include <iostream>
#include <math.h>
#include <iomanip>

#define left() j--
#define right() j++
#define up() i--
#define down() i++

#define put(val) array[i][j]=(val);

#define cell_unfree(y, x) array[i+y][j+x]!=0

void eratosfen(bool *primes, int size);
int next_square(int x);
int num_of_digits(int n);
bool is_a_square(int x);

int main(void){
  int num;
  printf("Введите до какого числа будет скатерть: ");
  scanf("%d", &num);
  printf("Программа выведет скатерть Улама до ближайшего числа, являющегося квадратом\n");
  putchar(10);
  num=next_square(num);
  int num_len=num_of_digits(num);
  
  char no_number[num_len+1];
  for(int i=0;i<num_len;i++)
    no_number[i]=' ';
  no_number[num_len]='\0';

  
  bool primes[num+1]; //Масскив всех простых чисел в [2, num]
  for(int i=0;i<num+1;i++)
    primes[i]=true;
  eratosfen(primes, num); // Населить массив простыми числами
  
  
  int dimensions=floor(sqrt(num));
  int array[dimensions][dimensions];
  for(int i=0;i<dimensions;i++)
    for(int j=0;j<dimensions;j++)
      array[i][j]=0;

  int i=dimensions/2;
  int j=num%2==0 ? dimensions/2-1 : dimensions/2;

  if(num==1) array[0][0]=-1;
  else if(num==4){
    array[0][0]=-1;
    array[0][1]=3;
    array[1][0]=-2;
    array[1][1]=2;
  }else{
    put(-2);
    right(); put(2);
    up();    put(3);
    left();
    int ind=4;
    while(true){
      while(cell_unfree(1, 0) && ind<=num){ //Снизу зан
	put(primes[ind++] ? ind-1 : -1);
	left();
      }
      if(ind>num) break;
      put(primes[ind++] ? ind-1 : -1);
      down();
      //----------------------------------------
      while(cell_unfree(0, 1) && ind<=num){ //справа зан
	put(primes[ind++] ? ind-1 : -1);
	down();
      }
      if(ind>num) break;
      put(primes[ind++] ? ind-1 : -1);
      right();
      //----------------------------------------
      while(cell_unfree(-1, 0) && ind<=num){ //сверху зан
	put(primes[ind++] ? ind-1 : -1);
	right();
      }
      if(ind>num) break;
      put(primes[ind++] ? ind-1 : -1);
      up();
      //----------------------------------------
      while(cell_unfree(0, -1) && ind<=num){ //слева зан
	put(primes[ind++] ? ind-1 : -1);
	up();
      }
      if(ind>num) break;
      put(primes[ind++] ? ind-1 : -1);
      left();
    }
  }

  
  for(int i=0;i<dimensions;i++){
    for(int j=0;j<dimensions;j++)
      if(array[i][j]==-1)
	printf("%s ", no_number);
      else if(array[i][j]==-2)
	std::cout<<std::setw(num_len)<<'!'<<" ";
      else
	std::cout<<std::setw(num_len)<<array[i][j]<<" ";
    putchar(10);
  }

  return 0;
}



bool is_a_square(int i){
  return sqrt(i)-floor(sqrt(i))==0;
}

void eratosfen(bool *primes, int size){
  primes[0]=false;  primes[1]=false;
  for(int i=2;i<=size;i++){
    if(primes[i]!=true) continue;
    for(int j=i+i;j<=size;j+=i)
      primes[j]=false;
  }
}

int next_square(int x){
  for(int i=x;;i++)
    if(is_a_square(i))
      return i;
}
int num_of_digits(int n){
  if(n==0) return 0;
  return 1+num_of_digits(n/10);
}
