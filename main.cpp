#include <iostream>
#include <exception>
#include <cmath>
#include "solution.h"
#include "series.h"

int main() {
  std::cout << "Hello, Margaret!" << std::endl;
  auto res = first_in_second(7, -123745);
  std::cout << "first_in_second: " << res << std::endl;
  std::cout << "is_prime: "<< is_prime(16129) << std::endl;
  std::cout << "there are " << number_of_ones(4095) << " bits" << std::endl;

  std::cout << "calculate_element: " << task2::calculate_element(3, 2.0) << std::endl;
  try {
    std::cout << "task2: " << task2::calculate_function(0.15, 0.00001, 50u, -1.0, 1.0) << std::endl;
    std::cout << "task2 check: " << (1.0 / sqrt(1u + 0.15)) << std::endl;
  }
  catch (std::exception& e) {
    std::cerr << e.what() << std::endl;
  }
  std::cin.get();
  return 0;
}
