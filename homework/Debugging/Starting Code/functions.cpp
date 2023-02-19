#include <iostream>
#include <stdexcept>

int Largest(int a, int b, int c) {
  int largest = a;
  if (b > largest) {
    largest = b;
  }
  if (c > largest) {
    largest = c;
  }
  return largest;
}

bool SumIsEven(int a, int b) {
  if ((a + b) % 2) {
    return false;
  }
  return true;
}

int BoxesNeeded(int apples) {
  if (apples < 0) {
    return 0;
  }
  return (apples + 19) / 20;
}

bool SmarterSection(int A_correct, int A_total, int B_correct, int B_total) {
  bool A_total_greater_than_correct = A_total >= A_correct;
  bool B_total_greater_than_correct = B_total >= B_correct;
  bool A_range_valid = A_correct >= 0 && A_total > 0;
  bool B_range_valid = B_correct >= 0 && B_total > 0;
  bool A_valid = A_total_greater_than_correct && A_range_valid;
  bool B_valid = B_total_greater_than_correct && B_range_valid;

  if (!A_valid || !B_valid) {
    throw std::invalid_argument("invalid argument");
  }

  double A_percent = A_correct / static_cast<double>(A_total);
  double B_percent = B_correct / static_cast<double>(B_total);

  if (A_percent > B_percent) {
    return true;
  }
  return false;
}

bool GoodDinner(int pizzas, bool is_weekend) {
  if (pizzas < 10) {
    return false;
  }

  if (is_weekend) {
    return true;
  }

  return pizzas <= 20;
}

int SumBetween(int low, int high) {
  if (low > high) {
    throw std::invalid_argument("invalid argument");
  }

  if (low == INT32_MIN && high == INT32_MAX) {
    return INT32_MIN;
  }

  if (low == high) {
    return low;
  }

  if (-low + 1 == high) {
    return high;
  }

  if (-low == high + 1) {
    return low;
  }

  long sum = static_cast<long>(high + low) * (high - low + 1) / 2;

  if (sum > INT32_MAX || sum < INT32_MIN) {
    throw std::overflow_error("overflow error");
  }

  return static_cast<int>(sum);
}

int Product(int a, int b) {
  int product = a * b;

  std::cout << "a: " << a << " b: " << b << std::endl;

  if ((a == -1 || b == -1) && (a == INT32_MIN || b == INT32_MIN)) {
    throw std::overflow_error("overflow error");
  }

  if (a != 0 && product / a != b) {
    throw std::overflow_error("overflow error");
  }

  if (b != 0 && product / b != a) {
    throw std::overflow_error("overflow error");
  }

  return product;
}
