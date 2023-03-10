bool triproduct_number(int n) {
  int a, b, c;
  a = 0;
  b = 1;
  c = 2;

  while (a * b * c <= n) {
    if (a * b * c == n) {
      return true;
    }

    a += 1;
    b += 1;
    c += 1;
  }

  return false;
}
