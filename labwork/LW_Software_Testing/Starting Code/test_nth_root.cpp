#include "./nth_root.h"
#include <cmath>
#include <iostream>

void test_nth_root(int n, double x, double expected) {
  try {
    double actual = nth_root(n, x);
    if (std::abs(actual - expected) < 0.0001) {
      std::cout << "[PASS] (n=" << n << ", x=" << x << ", expected=" << expected
                << ")" << std::endl;
    } else {
      std::cout << "[FAIL] (n=" << n << ", x=" << x << ", expected=" << expected
                << ")" << std::endl;
      std::cout << "  expected " << expected << " but got " << actual
                << std::endl;
    }
  } catch (...) {
    std::cout << "[FAIL] (n=" << n << ", x=" << x << ", expected=" << expected
              << ")" << std::endl;
    std::cout << "  expected " << expected << " but got "
              << "exception" << std::endl;
  }
}

void test_nth_root(int n, double x) {
  try {
    double actual = nth_root(n, x);
    std::cout << "[FAIL] (n=" << n << ", x=" << x << ", expected=exception"
              << ")" << std::endl;
    std::cout << "  expected exception "
              << " but got " << actual << std::endl;
  } catch (...) {
    std::cout << "[PASS] (n=" << n << ", x=" << x << ", expected=exception"
              << ")" << std::endl;
  }
}

int main() {
  // double actual = nth_root(0, 0); // throws std::domain_error
  // std::cout << "nth_root(0, 0) = " << actual << std::endl;

  // actual = nth_root(2, -1); // 0.5
  // std::cout << "nth_root(2, -1) = " << actual << std::endl;

  // actual = nth_root(-1, 0); // throws std::domain_error
  // std::cout << "nth_root(-1, 0) = " << actual << std::endl;

  // actual = nth_root(1, 0); // throws std::domain_error
  // std::cout << "nth_root(1, 0) = " << actual << std::endl;

  // actual = nth_root(-1, 1); // -1.0
  // std::cout << "nth_root(-1, 1) = " << actual << std::endl;

  // actual = nth_root(-7, 1); // -7.0
  // std::cout << "nth_root(-7, 1) = " << actual << std::endl;

  // actual = nth_root(-5, 1.5); // throws std::domain_error (imaginary number)
  // std::cout << "nth_root(-5, 1.5) = " << actual << std::endl;

  // actual = nth_root(7, 0); // throws std::domain_error
  // std::cout << "nth_root(7, 0) = " << actual << std::endl;

  // actual = nth_root(7, 7); // 1.3204692477561237
  // std::cout << "nth_root(7, 7) = " << actual << std::endl;

  // actual = nth_root(7, -7); // 0.7573065421245532
  // std::cout << "nth_root(7, -7) = " << actual << std::endl;

  test_nth_root(2, -1, 0.5);
  test_nth_root(-1, 1, -1.0);
  test_nth_root(-7, 1, -7.0);
  test_nth_root(7, 7, 1.3204692477561237);
  test_nth_root(7, -7, 0.7573065421245532);
  test_nth_root(-5, 1.5);
  test_nth_root(7, 0);
  test_nth_root(-1, 0);
  test_nth_root(1, 0);
  test_nth_root(0, 0);
}
