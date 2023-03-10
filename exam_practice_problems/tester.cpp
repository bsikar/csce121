#include "tester.h"
#include <iostream>

// Good Tests

// 1 input
template <typename A, typename U>
unsigned int run_good_test(A input, U expected, unsigned int test_num,
                           U (*func)(A)) {
  std::cout << "Test " << test_num << ": ";
  try {
    U output = func(input);
    if (output == expected) {
      std::cout << "passed" << std::endl;
      return 1;
    } else {
      std::cout << "failed: got " << output << std::endl;
      return 0;
    }
  } catch (std::invalid_argument &e) {
    std::cout << "failed: got " << e.what() << std::endl;
    return 0;
  }
}

// 2 input
template <typename A, typename B, typename U>
unsigned int run_good_test(A input1, B input2, U expected,
                           unsigned int test_num, U (*func)(A, B)) {
  std::cout << "Test " << test_num << ": ";
  try {
    U output = func(input1, input2);
    if (output == expected) {
      std::cout << "passed" << std::endl;
      return 1;
    } else {
      std::cout << "failed: got " << output << std::endl;
      return 0;
    }
  } catch (std::invalid_argument &e) {
    std::cout << "failed: got " << e.what() << std::endl;
    return 0;
  }
}

// 3 input
template <typename A, typename B, typename C, typename U>
unsigned int run_good_test(A input1, B input2, C input3, U expected,
                           unsigned int test_num, U (*func)(A, B, C)) {
  std::cout << "Test " << test_num << ": ";
  try {
    U output = func(input1, input2, input3);
    if (output == expected) {
      std::cout << "passed" << std::endl;
      return 1;
    } else {
      std::cout << "failed: got " << output << std::endl;
      return 0;
    }
  } catch (std::invalid_argument &e) {
    std::cout << "failed: got " << e.what() << std::endl;
    return 0;
  }
}

// 4 input
template <typename A, typename B, typename C, typename D, typename U>
unsigned int run_good_test(A input1, B input2, C input3, D input4, U expected,
                           unsigned int test_num, U (*func)(A, B, C, D)) {

  std::cout << "Test " << test_num << ": ";
  try {
    U output = func(input1, input2, input3, input4);
    if (output == expected) {
      std::cout << "passed" << std::endl;
      return 1;
    } else {
      std::cout << "failed: got " << output << std::endl;
      return 0;
    }
  } catch (std::invalid_argument &e) {
    std::cout << "failed: got " << e.what() << std::endl;
    return 0;
  }
}

// 5 input
template <typename A, typename B, typename C, typename D, typename E,
          typename U>
unsigned int run_good_test(A input1, B input2, C input3, D input4, E input5,
                           U expected, unsigned int test_num,
                           U (*func)(A, B, C, D, E)) {
  std::cout << "Test " << test_num << ": ";
  try {
    U output = func(input1, input2, input3, input4, input5);
    if (output == expected) {
      std::cout << "passed" << std::endl;
      return 1;
    } else {
      std::cout << "failed: got " << output << std::endl;
      return 0;
    }
  } catch (std::invalid_argument &e) {
    std::cout << "failed: got " << e.what() << std::endl;
    return 0;
  }
}

// 6 input
template <typename A, typename B, typename C, typename D, typename E,
          typename F, typename U>
unsigned int run_good_test(A input1, B input2, C input3, D input4, E input5,
                           F input6, U expected, unsigned int test_num,
                           U (*func)(A, B, C, D, E, F)) {
  std::cout << "Test " << test_num << ": ";
  try {
    U output = func(input1, input2, input3, input4, input5, input6);
    if (output == expected) {
      std::cout << "passed" << std::endl;
      return 1;
    } else {
      std::cout << "failed: got " << output << std::endl;
      return 0;
    }
  } catch (std::invalid_argument &e) {
    std::cout << "failed: got " << e.what() << std::endl;
    return 0;
  }
}

// Bad Tests

// 1 input
template <typename A, typename U>
unsigned int run_good_test(A input, unsigned int test_num, U (*func)(A)) {
  std::cout << "Test " << test_num << ": ";
  try {
    U output = func(input);
    std::cout << "failed: got " << output << std::endl;
    return 0;
  } catch (std::invalid_argument &e) {
    std::cout << "passed" << std::endl;
    return 1;
  }
}

// 2 input
template <typename A, typename B, typename U>
unsigned int run_good_test(A input1, B input2, unsigned int test_num,
                           U (*func)(A, B)) {
  std::cout << "Test " << test_num << ": ";
  try {
    U output = func(input1, input2);
    std::cout << "failed: got " << output << std::endl;
    return 0;
  } catch (std::invalid_argument &e) {
    std::cout << "passed" << std::endl;
    return 1;
  }
}

// 3 input
template <typename A, typename B, typename C, typename U>
unsigned int run_good_test(A input1, B input2, C input3, unsigned int test_num,
                           U (*func)(A, B, C)) {
  std::cout << "Test " << test_num << ": ";
  try {
    U output = func(input1, input2, input3);
    std::cout << "failed: got " << output << std::endl;
    return 0;
  } catch (std::invalid_argument &e) {
    std::cout << "passed" << std::endl;
    return 1;
  }
}

// 4 input
template <typename A, typename B, typename C, typename D, typename U>
unsigned int run_good_test(A input1, B input2, C input3, D input4,
                           unsigned int test_num, U (*func)(A, B, C, D)) {
  std::cout << "Test " << test_num << ": ";
  try {
    U output = func(input1, input2, input3, input4);
    std::cout << "failed: got " << output << std::endl;
    return 0;
  } catch (std::invalid_argument &e) {
    std::cout << "passed" << std::endl;
    return 1;
  }
}

// 5 input
template <typename A, typename B, typename C, typename D, typename E,
          typename U>
unsigned int run_good_test(A input1, B input2, C input3, D input4, E input5,
                           unsigned int test_num, U (*func)(A, B, C, D, E)) {
  std::cout << "Test " << test_num << ": ";
  try {
    U output = func(input1, input2, input3, input4, input5);
    std::cout << "failed: got " << output << std::endl;
    return 0;
  } catch (std::invalid_argument &e) {
    std::cout << "passed" << std::endl;
    return 1;
  }
}

// 6 input
template <typename A, typename B, typename C, typename D, typename E,
          typename F, typename U>
unsigned int run_good_test(A input1, B input2, C input3, D input4, E input5,
                           F input6, unsigned int test_num,
                           U (*func)(A, B, C, D, E, F)) {
  std::cout << "Test " << test_num << ": ";
  try {
    U output = func(input1, input2, input3, input4, input5, input6);
    std::cout << "failed: got " << output << std::endl;
    return 0;
  } catch (std::invalid_argument &e) {
    std::cout << "passed" << std::endl;
    return 1;
  }
}
