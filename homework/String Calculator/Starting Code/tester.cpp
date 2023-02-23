#include "string_calculator.h"
#include <iostream>

template <typename T, typename U>
int run_good_test(const T &input, const U &expected, int test_num,
                  U (*func)(const T &));

template <typename T>
int run_bad_test(const T &input, int test_num, TokenType (*func)(const T &));

void test_get_token_type();
void test_input_parser();

int main() {
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

template <typename T>
int run_bad_test(const T &input, int test_num, TokenType (*func)(const T &)) {
  std::cout << "Test " << test_num << ": ";
  try {
    TokenType output = func(input);
    std::cout << "failed: got " << output << std::endl;
    return 0;
  } catch (std::invalid_argument &e) {
    std::cout << "passed" << std::endl;
    return 1;
  }
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
  test_passed += run_bad_test<std::string>("1213a123", 4, get_token_type);

  // Test 5: invalid input - all alphabets
  test_count += 1;
  test_passed += run_bad_test<std::string>("aa", 5, get_token_type);

  // Test 6: invalid input - starts with alphabet
  test_count += 1;
  test_passed += run_bad_test<std::string>("a123", 6, get_token_type);

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
  test_passed += run_bad_test<std::string>("", 9, get_token_type);

  // Test 10: invalid input - space
  test_count += 1;
  test_passed += run_bad_test<std::string>(" ", 10, get_token_type);

  // Test 11: very large number
  test_count += 1;
  test_passed += run_good_test<std::string, TokenType>(
      "123456789012345678901234567890", TokenType::OPERAND, 11, get_token_type);

  // Test 12: input with only spaces
  test_count += 1;
  test_passed += run_bad_test<std::string>("   ", 12, get_token_type);

  // Test 13: input with leading spaces
  test_count += 1;
  test_passed += run_bad_test<std::string>("   123", 13, get_token_type);

  // Test 14: input with trailing spaces
  test_count += 1;
  test_passed += run_bad_test<std::string>("123   ", 14, get_token_type);

  // Test 15: input with leading and trailing spaces
  test_count += 1;
  test_passed += run_bad_test<std::string>("   123   ", 15, get_token_type);

  // Print results
  std::cout << "Passed " << test_passed << " out of " << test_count << " tests"
            << std::endl;
}

void test_input_parser() {
  int test_count = 0;
  int test_passed = 0;

  // Print results
  std::cout << "Passed " << test_passed << " out of " << test_count << " tests"
            << std::endl;
}
