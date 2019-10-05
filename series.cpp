#include <exception>
#include <stdexcept>
#include <limits>

#include "series.h"
#include "solution.h"


/********-task2-**********/
namespace task2 {

  unsigned long numerator(unsigned N) {
    unsigned long result = 1u;
    unsigned multiplier = 1u;
    for (unsigned i = 0u; i < N; ++i) {
      result *= multiplier;
      multiplier += 2u;
    }
    return result;
  }

  unsigned long denominator(unsigned N) {
    unsigned long result = 1u;
    unsigned multiplier = 2u;
    for (unsigned i = 0u; i < N; ++i) {
      result *= multiplier;
      multiplier += 2u;
    }
    return result;
  }

  double calculate_element(unsigned N, double x) {
    double val = ((double)numerator(N) / (double)denominator(N)) * int_pow(x, N);
    if (N % 2 != 0u) val = -val;
    return val;
  }

  double calculate_function(
      double x
    , double abs_error
    , unsigned number_max
    , double interval_from
    , double interval_to) {
    if (x < interval_from || x > interval_to)
      throw std::invalid_argument(
        "calculate_function: x is not in the specified interval");
    // get max value of double data type
    double last = std::numeric_limits<double>::max();
    double sum = 0.0;
    for (unsigned i = 1u; i <= number_max; ++i) {
      double current = calculate_element(i, x);
      sum += current;
      if (abs(current - last) <= abs_error)
        return (1.0 + sum); // OK
      last = current;
    }
    throw std::runtime_error("the specified accuracy is not achieved");
  }

} // !namespace task2
