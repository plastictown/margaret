// ���������� ������� ����� �� ����� ����������
constexpr double int_pow(double x, int pow, double res = 1.0) {
  return (pow <= 0) ? res : int_pow(x, pow - 1, res*x);
}

// ���������� ������� ����� �� ����� ����������
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