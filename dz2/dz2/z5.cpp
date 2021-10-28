#include <iostream>
#include <iomanip>

#define out(num1, num2)				\
  std::cout<<"|"<<std::setw(6)<<(num1)<<"|"<<std::setw(6)<<(num2)<<"|"<<std::endl;

float y(float x){
  return (x*x-2*x+2)/(x-1);
}

int main(void){
  std::cout.precision(3);
  std::cout<<"_______________"<<std::endl;
  std::cout<<"|   X  |  Y   |"<<std::endl;
  std::cout<<"|------+------|"<<std::endl;
  
  float x=-4-0.5;
  while(x<=3.5){
    x+=0.5;
    if(x==1) continue;
    out(x, y(x));
  }
  
  std::cout<<"~~~~~~~~~~~~~~~"<<std::endl;
  return 0;
}
