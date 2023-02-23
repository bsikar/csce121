#include "string_calculator.h"
#include <iostream>

template <typename T, typename U>
int run_good_test(const T &input, const U &expected, int test_num,
                  U (*func)(const T &));

template <typename T>
int run_good_test(T input, const T &e1, const T &e2, const T &e3, int test_num,
                  T *(*func)(T &));

template <typename T, typename U>
int run_bad_test(const T &input, int test_num, U (*func)(const T &));

template <typename T> int run_bad_test(T input, int test_num, T *(*func)(T &));

void test_clean_input();
void test_get_token_type();
void test_input_parser();

int main() {
  std::cout << "Running tests..." << std::endl;

  std::cout << "Testing `clean_input(...)`" << std::endl;
  std::cout << "----------------------------------------" << std::endl;
  test_clean_input();
  std::cout << "----------------------------------------" << std::endl;

  std::cout << "Testing the function `get_token_type(...)`" << std::endl;
  std::cout << "----------------------------------------" << std::endl;
  test_get_token_type();
  std::cout << "----------------------------------------" << std::endl;

  std::cout << "Testing the function `input_parser(...)`" << std::endl;
  std::cout << "----------------------------------------" << std::endl;
  test_input_parser();
  std::cout << "----------------------------------------" << std::endl;

  return 0;
}

template <typename T, typename U>
int run_good_test(const T &input, const U &expected, int test_num,
                  U (*func)(const T &)) {
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

template <typename T, typename U>
int run_bad_test(const T &input, int test_num, U (*func)(const T &)) {
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

template <typename T> int run_bad_test(T input, int test_num, T *(*func)(T &)) {
  std::cout << "Test " << test_num << ": ";
  try {
    T *output = func(input);
    std::cout << "failed: got " << output << std::endl;
    delete[] output;
    return 0;
  } catch (std::invalid_argument &e) {
    std::cout << "passed" << std::endl;
    return 1;
  }
}

template <typename T>
int run_good_test(T input, const T &e1, const T &e2, const T &e3, int test_num,
                  T *(*func)(T &)) {
  std::cout << "Test " << test_num << ": ";
  try {
    T *output = func(input);
    if (output[0] == e1 && output[1] == e2 && output[2] == e3) {
      std::cout << "passed" << std::endl;
      delete[] output;
      return 1;
    } else {
      std::cout << "failed: got " << output[0] << ", " << output[1] << ", "
                << output[2] << std::endl;
      delete[] output;
      return 0;
    }
  } catch (std::invalid_argument &e) {
    std::cout << "failed: got " << e.what() << std::endl;
    return 0;
  }
}

void test_clean_input() {
  int test_count = 0;
  int test_passed = 0;

  // Test 1: empty string
  test_count += 1;
  test_passed +=
      run_good_test<std::string, std::string>("", "", 1, clean_input);

  // Test 2: no whitespace
  test_count += 1;
  test_passed +=
      run_good_test<std::string, std::string>("1+2", "1 + 2", 2, clean_input);

  // Test 3: whitespace in the middle
  test_count += 1;
  test_passed +=
      run_good_test<std::string, std::string>("1 + 2", "1 + 2", 3, clean_input);

  // Test 4: whitespace at the beginning
  test_count += 1;
  test_passed += run_good_test<std::string, std::string>(" 1 + 2", "1 + 2", 4,
                                                         clean_input);

  // Test 5: whitespace at the end
  test_count += 1;
  test_passed += run_good_test<std::string, std::string>("1 + 2 ", "1 + 2", 5,
                                                         clean_input);

  // Test 6: whitespace at the beginning and end
  test_count += 1;
  test_passed += run_good_test<std::string, std::string>(" 1 + 2 ", "1 + 2", 6,
                                                         clean_input);

  // Test 7: multiple whitespace in the middle
  test_count += 1;
  test_passed += run_good_test<std::string, std::string>("1 +  2", "1 + 2", 7,
                                                         clean_input);

  // Test 8: multiple whitespace at the beginning
  test_count += 1;
  test_passed += run_good_test<std::string, std::string>("  1 + 2", "1 + 2", 8,
                                                         clean_input);

  // Test 9: multiple whitespace at the end
  test_count += 1;
  test_passed += run_good_test<std::string, std::string>("1 + 2  ", "1 + 2", 9,
                                                         clean_input);

  // Test 10: multiple whitespace at the beginning and end
  test_count += 1;
  test_passed += run_good_test<std::string, std::string>("  1 + 2  ", "1 + 2",
                                                         10, clean_input);

  // Test 11: multiple whitespace in the middle, beginning, and end
  test_count += 1;
  test_passed += run_good_test<std::string, std::string>("  1 +  2  ", "1 + 2",
                                                         11, clean_input);

  // Test 12: multiple whitespace in the middle, beginning, and end
  test_count += 1;
  test_passed += run_good_test<std::string, std::string>("  1 +  2  ", "1 + 2",
                                                         12, clean_input);

  // Test 13: multiple whitespace in the middle, beginning, and end
  test_count += 1;
  test_passed += run_good_test<std::string, std::string>("  1 +  2  ", "1 + 2",
                                                         13, clean_input);

  // Test 14: whitespace at the beginning, but not in the middle
  test_count += 1;
  test_passed +=
      run_good_test<std::string, std::string>(" 1+2", "1 + 2", 14, clean_input);

  // Test 15: whitespace at the end, but not in the middle
  test_count += 1;
  test_passed +=
      run_good_test<std::string, std::string>("1+2 ", "1 + 2", 15, clean_input);

  // Test 16: whitespace at the beginning and end, but not the middle
  test_count += 1;
  test_passed += run_good_test<std::string, std::string>(" 1+2 ", "1 + 2", 16,
                                                         clean_input);

  // Test 17: multiple whitespace at the beginning, but not in the middle
  test_count += 1;
  test_passed += run_good_test<std::string, std::string>("  1+2", "1 + 2", 17,
                                                         clean_input);

  // Test 18: multiple whitespace at the end, but not in the middle
  test_count += 1;
  test_passed += run_good_test<std::string, std::string>("1+2  ", "1 + 2", 18,
                                                         clean_input);

  // Test 19: multiple whitespace at the beginning and end, but not the middle
  test_count += 1;
  test_passed += run_good_test<std::string, std::string>("  1+2  ", "1 + 2", 19,
                                                         clean_input);

  // Print the results
  std::cout << "Passed " << test_passed << " out of " << test_count << " tests."
            << std::endl;
}

void test_get_token_type() {
  int test_count = 0;
  int test_passed = 0;

  // Test 1: single digit operand
  test_count += 1;
  test_passed += run_good_test<std::string, TokenType>("1", TokenType::OPERAND,
                                                       1, get_token_type);

  // Test 2: multiple zero digits operand
  test_count += 1;
  test_passed += run_good_test<std::string, TokenType>(
      "000000", TokenType::OPERAND, 2, get_token_type);

  // Test 3: multi-digit operand
  test_count += 1;
  test_passed += run_good_test<std::string, TokenType>(
      "123", TokenType::OPERAND, 3, get_token_type);

  // Test 4: invalid input - alpha numeric
  test_count += 1;
  test_passed +=
      run_bad_test<std::string, TokenType>("1213a123", 4, get_token_type);

  // Test 5: invalid input - all alphabets
  test_count += 1;
  test_passed += run_bad_test<std::string, TokenType>("aa", 5, get_token_type);

  // Test 6: invalid input - starts with alphabet
  test_count += 1;
  test_passed +=
      run_bad_test<std::string, TokenType>("a123", 6, get_token_type);

  // Test 7: operator test - plus
  test_count += 1;
  test_passed += run_good_test<std::string, TokenType>("+", TokenType::OPERATOR,
                                                       7, get_token_type);

  // Test 8: operator test - multiplication
  test_count += 1;
  test_passed += run_good_test<std::string, TokenType>("*", TokenType::OPERATOR,
                                                       8, get_token_type);

  // Test 9: invalid input - empty string
  test_count += 1;
  test_passed += run_bad_test<std::string, TokenType>("", 9, get_token_type);

  // Test 10: invalid input - space
  test_count += 1;
  test_passed += run_bad_test<std::string, TokenType>(" ", 10, get_token_type);

  // Test 11: very large number
  test_count += 1;
  test_passed += run_good_test<std::string, TokenType>(
      "123456789012345678901234567890", TokenType::OPERAND, 11, get_token_type);

  // Test 12: input with only spaces
  test_count += 1;
  test_passed +=
      run_bad_test<std::string, TokenType>("   ", 12, get_token_type);

  // Test 13: input with leading spaces
  test_count += 1;
  test_passed +=
      run_bad_test<std::string, TokenType>("   123", 13, get_token_type);

  // Test 14: input with trailing spaces
  test_count += 1;
  test_passed +=
      run_bad_test<std::string, TokenType>("123   ", 14, get_token_type);

  // Test 15: input with leading and trailing spaces
  test_count += 1;
  test_passed +=
      run_bad_test<std::string, TokenType>("   123   ", 15, get_token_type);

  // Print results
  std::cout << "Passed " << test_passed << " out of " << test_count << " tests"
            << std::endl;
}

void test_input_parser() {
  int test_count = 0;
  int test_passed = 0;

  // Test 1: single digit operands
  test_count += 1;
  test_passed +=
      run_good_test<std::string>("1+2", "+", "1", "2", 1, input_parser);

  // Test 2: multi-digit operands
  test_count += 1;
  test_passed +=
      run_good_test<std::string>("10*100", "*", "10", "100", 2, input_parser);

  // Test 3 : invalid input - missing operand test_count += 1;
  test_count += 1;
  test_passed += run_bad_test<std::string>("1+", 3, input_parser);

  // Test 4: invalid input - missing operator
  test_count += 1;
  test_passed += run_bad_test<std::string>("1 2", 4, input_parser);

  // Test 5: invalid input - extra operator
  test_count += 1;
  test_passed += run_bad_test<std::string>("1++2", 5, input_parser);

  // Test 6: invalid input - extra operand
  test_count += 1;
  test_passed += run_bad_test<std::string>("1+2+3", 6, input_parser);

  // Print results
  std::cout << "Passed " << test_passed << " out of " << test_count << " tests"
            << std::endl;
}
