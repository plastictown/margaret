#pragma once

#ifndef  __SERIES_H__
#define __SERIES_H__

namespace task2 {
  unsigned long numerator(unsigned N);
  unsigned long denominator(unsigned N);
  double calculate_element(unsigned N, double x);
  double calculate_function(
    double x
    , double abs_error
    , unsigned number_max
    , double interval_from
    , double interval_to);
}



#endif // ! __SERIES_H__
