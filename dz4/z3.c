#include <stdio.h>
#include <math.h>

#define PI 3.1415926

float circle(float R){
  return PI*R*R;
}

float rectangle(float a, float b){
  return a*b;
}

float triangle(float a, float b, float c){
  float p=(a+b+c)/2;
  float tmp=p*(p-a)*(p-b)*(p-c);
  return tmp<0 ? -1 : sqrt(tmp);
}

int main(void){
  int ans;
  printf("Площадь какой фигуры вы хотите посчитать?\n1) Круг\n2) Прямоугольник\n3) Треугольник\n");
  scanf("%d", &ans);
  float R, a, b, c;
  switch(ans){
  case 1:
    printf("Введите радиус круга: ");
    scanf("%f", &R);
    if(R<0)
      printf("Радиус не может быть меньше нуля\n");
    else
      printf("Площадь круга = %f\n", circle(R));
    break;
  case 2:
    printf("Введите длины сторон прямоугольника: ");
    scanf("%f %f", &a, &b);
    if(a<0 || b<0)
      printf("Длина не может быть отрицательной\n");
    else
      printf("Площадь прямоугольника = %f\n", rectangle(a, b));
    break;
  case 3:
    printf("Введите длины всех сторон треугольника\n");
    float a, b, c;
    scanf("%f %f %f", &a, &b, &c);
    if(a<0 || b<0 || c<0 || triangle(a, b, c)==-1)
      printf("Такого треугольника не существует\n");
    else
      printf("Площадь треугольника = %f\n", triangle(a, b, c));
    break;
  default:
    printf("Такой вариант ответа выбрать нельзя!!!\n");
    main();
  }
  return 0;
}
