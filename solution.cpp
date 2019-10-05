#include "solution.h"

// вычисление степени числа во время компиляции
constexpr double int_pow(double x, int pow, double res = 1.0) {
  return (pow <= 0) ? res : int_pow(x, pow - 1, res*x);
}

// вычисление степени числа во время исполнения
double int_pow(double x, unsigned pow) {
  // для степеней 0 и 1 результат готов
  if (pow == 0.0) return 1.0;
  if (pow == 1u) return x;

  double res = 1.0;
  // перемножаем x pow раз
  for (auto i = 0u; i < pow; ++i) {
    res *= x;
  }
  return res;
}

// количество десятичных разрядов числа
unsigned decimal_places(int N) {
  unsigned res = 0; // число разрядов
  unsigned divisor = 1u; // текущий делитель
  if (N < 0) N = -N; // модуль
  while (N / divisor) {
    ++res;
    divisor *= 10u;
  }
  return res;
}

// содержит ли десятичное число second цифру first
bool first_in_second(int first, int second) {
  // количество разрядов
  unsigned n_places = decimal_places(second);
  // убираем знаки (abs)
  if (first < 0) first = -first;
  if (second < 0) second = -second;

  // берем остаток от деления
  // на rem и делим на div.
  // результат: значение разряда числа

  unsigned div = 1u, rem = 10u;
  for (auto i = 0u; i < n_places; ++i) {
    // текущий разряд
    int cur = (second % rem) / div;
    // если текущий разряд == first, цифра найдена
    if (cur == first) return true;
    // переходим к следующему разряду
    div *= 10u;
    rem *= 10u;
  }
  // цифра first отсутствует в second
  return false;
}

// простое ли число?
bool is_prime(unsigned n) {
  if (n < 3) return true;
  if (n % 2 == 0) return false;
  for (unsigned long m = 3u; m <= n/2; m += 2u)
  {
    if (n % m == 0u)
      return false;
  }
  return true;
}

// количество единиц в двоичной записи
unsigned number_of_ones(int N) {
  // number of bits
  unsigned len = sizeof(N) * 8u;
  decltype(N) mask = 1;
  //result
  unsigned num = 0;
  for (unsigned i = 0; i < len; ++i) {
    if (N & mask) ++num;
    mask <<= 1;
  }
  return num;
}
