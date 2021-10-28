#include <iostream>
#include <iomanip>

#define out(num1, num2)				\
  std::cout<<"|";				\
  std::cout<<std::fixed<<std::setprecision(1);	\
  std::cout<<std::setw(6)<<(num1)<<"  |";	\
  std::cout<<std::fixed<<std::setprecision(3);	\
  std::cout<<std::setw(8)<<(num2)<<" |";	\
  std::cout<<std::endl;

float y(float x){
  return (x*x-2*x+2)/(x-1);
}

int main(void){
  std::cout.precision(3);
  std::cout<<"____________________"<<std::endl;

  std::cout<<"| __  __ |  _   _  |"<<std::endl;
  std::cout<<"| \\ \\/ / | | | | | |"<<std::endl;
  std::cout<<"|  >  <  | | |_| | |"<<std::endl;
  std::cout<<"| /_/\\_\\ |  \\__, | |"<<std::endl;
  std::cout<<"|        |  |___/  |"<<std::endl;
  
  std::cout<<"|--------+---------|"<<std::endl;
  
  float x=-4-0.5;
  while(x<=3.5){
    x+=0.5;
    if(x==1) continue;
    out(x, y(x));
  }
  
  std::cout<<"~~~~~~~~~~~~~~~~~~~~"<<std::endl;
  return 0;
}
