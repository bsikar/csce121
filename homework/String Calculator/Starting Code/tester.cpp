#include "string_calculator.h"
#include <iostream>

template <typename T, typename U>
int run_good_test(const T &input, const U &expected, int test_num,
                  U (*func)(const T &));

template <typename T, typename U>
int run_good_test(T input, U expected, int test_num, U (*func)(T));

template <typename T>
int run_good_test(T input, const T &e1, const T &e2, const T &e3, int test_num,
                  T *(*func)(T &));

template <typename T>
int run_good_test(const T &input1, const T &input2, const T &expected,
                  int test_num, T (*func)(const T &, const T &));

template <typename T, typename U>
int run_bad_test(const T &input, int test_num, U (*func)(const T &));

template <typename T> int run_bad_test(T input, int test_num, T *(*func)(T &));

void test_clean_input();
void test_get_token_type();
void test_input_parser();
void test_add();
void test_digit_to_decimal();
void test_decimal_to_digit();
void test_trim_leading_zeros();
void test_remove_extra_whitespace();
void test_add_extra_whitespace();

// TODO: implement these
void test_multiply();
void test_calculate();

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

  std::cout << "Testing the function `add(...)`" << std::endl;
  std::cout << "----------------------------------------" << std::endl;
  test_add();
  std::cout << "----------------------------------------" << std::endl;

  std::cout << "Testing the function `digit_to_decimal(...)`" << std::endl;
  std::cout << "----------------------------------------" << std::endl;
  test_digit_to_decimal();
  std::cout << "----------------------------------------" << std::endl;

  std::cout << "Testing the function `decimal_to_digit(...)`" << std::endl;
  std::cout << "----------------------------------------" << std::endl;
  test_decimal_to_digit();
  std::cout << "----------------------------------------" << std::endl;

  std::cout << "Testing the function `trim_leading_zeros(...)`" << std::endl;
  std::cout << "----------------------------------------" << std::endl;
  test_trim_leading_zeros();
  std::cout << "----------------------------------------" << std::endl;

  std::cout << "Testing the function `remove_extra_whitespace(...)`"
            << std::endl;
  std::cout << "----------------------------------------" << std::endl;
  test_remove_extra_whitespace();
  std::cout << "----------------------------------------" << std::endl;

  std::cout << "Testing the function `add_extra_whitespace(...)`" << std::endl;
  std::cout << "----------------------------------------" << std::endl;
  test_add_extra_whitespace();
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

template <typename T>
int run_good_test(const T &input1, const T &input2, const T &expected,
                  int test_num, T (*func)(const T &, const T &)) {
  std::cout << "Test " << test_num << ": ";
  try {
    T output = func(input1, input2);
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
int run_good_test(T input, U expected, int test_num, U (*func)(T)) {
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

void test_add() {
  int test_count = 0;
  int test_passed = 0;

  // Test 1: single digit operands
  test_count += 1;
  test_passed += run_good_test<std::string>("1", "2", "3", 1, add);

  // Test 2: multi-digit operands
  test_count += 1;
  test_passed += run_good_test<std::string>("10", "100", "110", 2, add);

  // Test 3: negative operands
  test_count += 1;
  test_passed += run_good_test<std::string>("-10", "100", "90", 3, add);

  // Test 4: negative operands
  test_count += 1;
  test_passed += run_good_test<std::string>("10", "-100", "-90", 4, add);

  // Test 5: negative operands
  test_count += 1;
  test_passed += run_good_test<std::string>("-10", "-100", "-110", 5, add);

  // Test 6: zero operands
  test_count += 1;
  test_passed += run_good_test<std::string>("0", "0", "0", 6, add);

  // Test 7: zero operands
  test_count += 1;
  test_passed += run_good_test<std::string>("0", "100", "100", 7, add);

  // Test 8: zero operands
  test_count += 1;
  test_passed += run_good_test<std::string>("-10", "0", "-10", 8, add);

  // Test 9: zero operands
  test_count += 1;
  test_passed += run_good_test<std::string>("0", "-100", "-100", 9, add);

  // Test 10: very large operands
  test_count += 1;
  test_passed += run_good_test<std::string>("1234567890", "1234567890",
                                            "2469135780", 10, add);

  // Test 11: very large operands
  test_count += 1;
  test_passed +=
      run_good_test<std::string>("-1234567890", "1234567890", "0", 11, add);

  // Print results
  std::cout << "Passed " << test_passed << " out of " << test_count << " tests"
            << std::endl;
}

void test_digit_to_decimal() {
  int test_count = 0;
  int test_passed = 0;

  // Test 1: 1
  test_count += 1;
  test_passed += run_good_test<char, unsigned int>('1', 1, 1, digit_to_decimal);

  // Test 2: 2
  test_count += 1;
  test_passed += run_good_test<char, unsigned int>('2', 2, 2, digit_to_decimal);

  // Test 3: 3
  test_count += 1;
  test_passed += run_good_test<char, unsigned int>('3', 3, 3, digit_to_decimal);

  // Test 4: 4
  test_count += 1;
  test_passed += run_good_test<char, unsigned int>('4', 4, 4, digit_to_decimal);

  // Test 5: 5
  test_count += 1;
  test_passed += run_good_test<char, unsigned int>('5', 5, 5, digit_to_decimal);

  // Test 6: 6
  test_count += 1;
  test_passed += run_good_test<char, unsigned int>('6', 6, 6, digit_to_decimal);

  // Test 7: 7
  test_count += 1;
  test_passed += run_good_test<char, unsigned int>('7', 7, 7, digit_to_decimal);

  // Test 8: 8
  test_count += 1;
  test_passed += run_good_test<char, unsigned int>('8', 8, 8, digit_to_decimal);

  // Test 9: 9
  test_count += 1;
  test_passed += run_good_test<char, unsigned int>('9', 9, 9, digit_to_decimal);

  // Test 10: 0
  test_count += 1;
  test_passed +=
      run_good_test<char, unsigned int>('0', 0, 10, digit_to_decimal);

  // Print results
  std::cout << "Passed " << test_passed << " out of " << test_count << " tests"
            << std::endl;
}

void test_decimal_to_digit() {
  int test_count = 0;
  int test_passed = 0;

  // Test 1: 1
  test_count += 1;
  test_passed += run_good_test<unsigned int, char>(1, '1', 1, decimal_to_digit);

  // Test 2: 2
  test_count += 1;
  test_passed += run_good_test<unsigned int, char>(2, '2', 2, decimal_to_digit);

  // Test 3: 3
  test_count += 1;
  test_passed += run_good_test<unsigned int, char>(3, '3', 3, decimal_to_digit);

  // Test 4: 4
  test_count += 1;
  test_passed += run_good_test<unsigned int, char>(4, '4', 4, decimal_to_digit);

  // Test 5: 5
  test_count += 1;
  test_passed += run_good_test<unsigned int, char>(5, '5', 5, decimal_to_digit);

  // Test 6: 6
  test_count += 1;
  test_passed += run_good_test<unsigned int, char>(6, '6', 6, decimal_to_digit);

  // Test 7: 7
  test_count += 1;
  test_passed += run_good_test<unsigned int, char>(7, '7', 7, decimal_to_digit);

  // Test 8: 8
  test_count += 1;
  test_passed += run_good_test<unsigned int, char>(8, '8', 8, decimal_to_digit);

  // Test 9: 9
  test_count += 1;
  test_passed += run_good_test<unsigned int, char>(9, '9', 9, decimal_to_digit);

  // Test 10: 0
  test_count += 1;
  test_passed +=
      run_good_test<unsigned int, char>(0, '0', 10, decimal_to_digit);

  // Print results
  std::cout << "Passed " << test_passed << " out of " << test_count << " tests"
            << std::endl;
}

void test_trim_leading_zeros() {
  int test_count = 0;
  int test_passed = 0;

  // Test 1: empty string
  test_count += 1;
  test_passed +=
      run_good_test<std::string, std::string>("", "", 1, trim_leading_zeros);

  // Test 2: single zero
  test_count += 1;
  test_passed +=
      run_good_test<std::string, std::string>("0", "0", 2, trim_leading_zeros);

  // Test 3: single non-zero
  test_count += 1;
  test_passed +=
      run_good_test<std::string, std::string>("1", "1", 3, trim_leading_zeros);

  // Test 4: multiple zeros
  test_count += 1;
  test_passed += run_good_test<std::string, std::string>("000", "0", 4,
                                                         trim_leading_zeros);

  // Test 5: multiple zeros
  test_count += 1;
  test_passed += run_good_test<std::string, std::string>("0001", "1", 5,
                                                         trim_leading_zeros);

  // Test 6: multiple zeros
  test_count += 1;
  test_passed += run_good_test<std::string, std::string>("000123", "123", 6,
                                                         trim_leading_zeros);

  // Test 7: multiple zeros
  test_count += 1;
  test_passed += run_good_test<std::string, std::string>("000123000", "123000",
                                                         7, trim_leading_zeros);

  // Test 8: multiple zeros
  test_count += 1;
  test_passed += run_good_test<std::string, std::string>(
      "0000001200003000000", "1200003000000", 8, trim_leading_zeros);

  // Test 9: multiple zeros
  test_count += 1;
  test_passed += run_good_test<std::string, std::string>(
      "0123000000000", "123000000000", 9, trim_leading_zeros);

  // Test 10: multiple zeros
  test_count += 1;
  test_passed += run_good_test<std::string, std::string>(
      "0000123000000000000", "123000000000000", 10, trim_leading_zeros);

  // Test 11: multiple zeros
  test_count += 1;
  test_passed += run_good_test<std::string, std::string>(
      "0000000000123000000000000000", "123000000000000000", 11,
      trim_leading_zeros);

  // Print results
  std::cout << "Passed " << test_passed << " out of " << test_count << " tests"
            << std::endl;
}

void test_remove_extra_whitespace() {
  int test_count = 0;
  int test_passed = 0;

  // Test 1: empty string
  test_count += 1;
  test_passed += run_good_test<std::string, std::string>(
      "", "", 1, remove_extra_whitespace);

  // Test 2: single space
  test_count += 1;
  test_passed += run_good_test<std::string, std::string>(
      " ", "", 2, remove_extra_whitespace);

  // Test 3: single tab
  test_count += 1;
  test_passed += run_good_test<std::string, std::string>(
      "\t", "", 3, remove_extra_whitespace);

  // Test 4: single newline
  test_count += 1;
  test_passed += run_good_test<std::string, std::string>(
      "\n", "", 4, remove_extra_whitespace);

  // Test 5: string with no extra whitespace
  test_count += 1;
  test_passed += run_good_test<std::string, std::string>(
      "a b c", "a b c", 5, remove_extra_whitespace);

  // Test 6: string with multiple spaces
  test_count += 1;
  test_passed += run_good_test<std::string, std::string>(
      "  a   b  c   ", "a b c", 6, remove_extra_whitespace);

  // Test 7: string with tabs and newlines
  test_count += 1;
  test_passed += run_good_test<std::string, std::string>(
      "a\tb\n  c\td\n", "a b c d", 7, remove_extra_whitespace);

  // Test 8: string with only whitespace
  test_count += 1;
  test_passed += run_good_test<std::string, std::string>(
      "   \t\n", "", 8, remove_extra_whitespace);

  // Test 9: string with leading and trailing whitespace
  test_count += 1;
  test_passed += run_good_test<std::string, std::string>(
      "  a b c   ", "a b c", 9, remove_extra_whitespace);

  // Test 10: string with multiple consecutive tabs and spaces
  test_count += 1;
  test_passed += run_good_test<std::string, std::string>(
      "a    \t   b    c", "a b c", 10, remove_extra_whitespace);

  // Test 11: string with mixed whitespace characters
  test_count += 1;
  test_passed += run_good_test<std::string, std::string>(
      "a\t    b   \n c  \t\t d", "a b c d", 11, remove_extra_whitespace);

  // Test 12: string with only one character
  test_count += 1;
  test_passed += run_good_test<std::string, std::string>(
      "a", "a", 12, remove_extra_whitespace);

  // Print results
  std::cout << "Passed " << test_passed << " out of " << test_count << " tests"
            << std::endl;
}

void test_add_extra_whitespace() {
  int test_count = 0;
  int test_passed = 0;

  // Test 1: empty string
  test_count += 1;
  test_passed +=
      run_good_test<std::string, std::string>("", "", 1, add_extra_whitespace);

  // Test 2: string with no '+' or '*' characters
  test_count += 1;
  test_passed += run_good_test<std::string, std::string>(
      "hello world", "hello world", 2, add_extra_whitespace);

  // Test 3: string with a '+' character
  test_count += 1;
  test_passed += run_good_test<std::string, std::string>("1+2", "1 + 2", 3,
                                                         add_extra_whitespace);

  // Test 4: string with a '*' character
  test_count += 1;
  test_passed += run_good_test<std::string, std::string>("2*3", "2 * 3", 4,
                                                         add_extra_whitespace);

  // Test 5: string with '+' and '*' characters
  test_count += 1;
  test_passed += run_good_test<std::string, std::string>(
      "1+2*3", "1 + 2 * 3", 5, add_extra_whitespace);

  // Test 6: string with multiple '+' and '*' characters
  test_count += 1;
  test_passed += run_good_test<std::string, std::string>(
      "1+2*3+4", "1 + 2 * 3 + 4", 6, add_extra_whitespace);

  // Test 7: string with '+' and '*' characters and leading/trailing whitespace
  test_count += 1;
  test_passed += run_good_test<std::string, std::string>(
      " 1 +2 *3 + 4 ", " 1  + 2  * 3  +  4 ", 7, add_extra_whitespace);

  // Test 8: string with '+' and '*' characters and already existing whitespace
  test_count += 1;
  test_passed += run_good_test<std::string, std::string>(
      "1 + 2* 3", "1  +  2 *  3", 8, add_extra_whitespace);

  // Test 9: string with only one digit and '*' character
  test_count += 1;
  test_passed += run_good_test<std::string, std::string>("2*", "2 * ", 9,
                                                         add_extra_whitespace);

  // Test 10: string with only one digit and '+' character
  test_count += 1;
  test_passed += run_good_test<std::string, std::string>("5+", "5 + ", 10,
                                                         add_extra_whitespace);

  // Test 11: string with multiple '*' characters together
  test_count += 1;
  test_passed += run_good_test<std::string, std::string>("6**7", "6 *  * 7", 11,
                                                         add_extra_whitespace);

  // Test 12: string with multiple '+' characters together
  test_count += 1;
  test_passed += run_good_test<std::string, std::string>("8++9", "8 +  + 9", 12,
                                                         add_extra_whitespace);

  // Print results
  std::cout << "Passed " << test_passed << " out of " << test_count << " tests"
            << std::endl;
}
