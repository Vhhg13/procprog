#include <iostream>
#include <iomanip>


int main(void){
  float a, b;
  a = 0.3;
  b = 0;
  for (char i = 1; i <= 50; i++) {
    b = b + a;
  };
  std::cout.precision(7);
  std::cout << b << std::endl;
  return 0;
}
