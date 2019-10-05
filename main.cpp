#include <iostream>
#include "solution.h"


int main() {
  std::cout << "Hello, Margaret!" << std::endl;
  auto res = first_in_second(7, -123745);
  std::cout << "first_in_second: " << res << std::endl;
  std::cin.get();
  return 0;
}