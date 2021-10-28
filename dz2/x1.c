#include <stdio.h>
#include <math.h>

#define false 0
#define true 1
#define PI 3.14159


#define negative_value(val, str)		\
  if(val<0){					\
    if(with_negatives) printf("А ещё ");	\
    with_negatives=true;			\
    printf(str);				\
    val=-val;					\
  }


int main(void){
  
  _Bool with_negatives=false; // Нужно если введено больше одного отрицательного значения. В таком случае приписываем в начале "А ещё"
  
  printf("Введите h, R, r\n");
  float h, R, r;
  scanf("%f %f %f", &h, &R, &r);

  
  if(h==0){
    printf("Высота конуса не может быть равна нулю\n");
    return 0;
  }

  // Перед вот этими строками может добавиться "А ещё"
  negative_value(h, "Вы ввели значение высоты ниже нуля, будем считать, что она положительна\n");
  negative_value(R, "Вы ввели значение большего радиуса меньше нуля, будем считать, что он положителен\n");
  negative_value(r, "Вы ввели значение меньшего радиуса меньше нуля, будем считать, что он положителен\n");
  
  if(r>R){
    if(with_negatives) printf("А ещё ");
    printf("Вы ввели r>R, будем считать, что r=%.3f и R=%.3f\n", R, r);
  }

  float delta_r=fabsf(R-r);
  float l=sqrt(h*h+delta_r*delta_r);
  
  
  float V=h*(R*R+R*r+r*r)/3.0;
  float S=R*R+(R+r)*l+r*r;
  
  if(V*S==0)
    printf("Фигуры с такими параметрами не существует\n");
  else
    printf("V=%.3f*pi=%.3f\nS=%.3f*pi=%.3f\n", V, V*PI, S, S*PI);

  
  return 0;
}
