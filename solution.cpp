#include "solution.h"

// ���������� ������� �����
double int_pow(double x, unsigned pow) {
  // ��� �������� 0 � 1 ��������� �����
  if (pow == 0.0) return 1.0;
  if (pow == 1u) return x;

  double res = 1.0;
  // ����������� x pow ���
  for (auto i = 0u; i < pow; ++i) {
    res *= x;
  }
  return res;
}

// ���������� ����������
unsigned long fact(unsigned N) {
  unsigned long res = 1ul;
  while (N > 1) {
    res *= N;
    --N;
  }
  return res;
}

// ���������� ���������� �������� �����
unsigned decimal_places(int N) {
  unsigned res = 0; // ����� ��������
  unsigned divisor = 1u; // ������� ��������
  if (N < 0) N = -N; // ������
  while (N / divisor) {
    ++res;
    divisor *= 10u;
  }
  return res;
}

// �������� �� ���������� ����� second ����� first
bool first_in_second(int first, int second) {
  // ���������� ��������
  unsigned n_places = decimal_places(second);
  // ������� ����� (abs)
  if (first < 0) first = -first;
  if (second < 0) second = -second;

  // ����� ������� �� �������
  // �� rem � ����� �� div.
  // ���������: �������� ������� �����

  unsigned div = 1u, rem = 10u;
  for (auto i = 0u; i < n_places; ++i) {
    // ������� ������
    int cur = (second % rem) / div;
    // ���� ������� ������ == first, ����� �������
    if (cur == first) return true;
    // ��������� � ���������� �������
    div *= 10u;
    rem *= 10u;
  }
  // ����� first ����������� � second
  return false;
}

// ������� �� �����?
bool is_prime(unsigned n) {
  if (n < 3u) return true;
  if (n % 2u == 0) return false;
  for (unsigned long m = 3u; m <= n/2u; m += 2u)
  {
    if (n % m == 0u)
      return false;
  }
  return true;
}

// ���������� ������ � �������� ������
unsigned number_of_ones(int N) {
  // number of bits
  unsigned len = sizeof(N) * 8u;
  decltype(N) mask = 1;
  //result
  unsigned num = 0u;
  for (unsigned i = 0u; i < len; ++i) {
    if (N & mask) ++num;
    mask <<= 1;
  }
  return num;
}
