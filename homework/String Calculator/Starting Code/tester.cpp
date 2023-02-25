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
                  int test_num, T (*func)(T, T));

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
void test_multiply();
void test_subract();

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

  std::cout << "Testing the function `multiply(...)`" << std::endl;
  std::cout << "----------------------------------------" << std::endl;
  test_multiply();
  std::cout << "----------------------------------------" << std::endl;

  std::cout << "Testing the function `subract(...)`" << std::endl;
  std::cout << "----------------------------------------" << std::endl;
  test_subract();
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
                  int test_num, T (*func)(T, T)) {
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

  test_count += 1;
  test_passed +=
      run_good_test<std::string, std::string>("", "", 1, clean_input);

  test_count += 1;
  test_passed +=
      run_good_test<std::string, std::string>("1+2", "1 + 2", 2, clean_input);

  test_count += 1;
  test_passed +=
      run_good_test<std::string, std::string>("1 + 2", "1 + 2", 3, clean_input);

  test_count += 1;
  test_passed += run_good_test<std::string, std::string>(" 1 + 2", "1 + 2", 4,
                                                         clean_input);

  test_count += 1;
  test_passed += run_good_test<std::string, std::string>("1 + 2 ", "1 + 2", 5,
                                                         clean_input);

  test_count += 1;
  test_passed += run_good_test<std::string, std::string>(" 1 + 2 ", "1 + 2", 6,
                                                         clean_input);

  test_count += 1;
  test_passed += run_good_test<std::string, std::string>("1 +  2", "1 + 2", 7,
                                                         clean_input);

  test_count += 1;
  test_passed += run_good_test<std::string, std::string>("  1 + 2", "1 + 2", 8,
                                                         clean_input);

  test_count += 1;
  test_passed += run_good_test<std::string, std::string>("1 + 2  ", "1 + 2", 9,
                                                         clean_input);

  test_count += 1;
  test_passed += run_good_test<std::string, std::string>("  1 + 2  ", "1 + 2",
                                                         10, clean_input);

  test_count += 1;
  test_passed += run_good_test<std::string, std::string>("  1 +  2  ", "1 + 2",
                                                         11, clean_input);

  test_count += 1;
  test_passed += run_good_test<std::string, std::string>("  1 +  2  ", "1 + 2",
                                                         12, clean_input);

  test_count += 1;
  test_passed += run_good_test<std::string, std::string>("  1 +  2  ", "1 + 2",
                                                         13, clean_input);

  test_count += 1;
  test_passed +=
      run_good_test<std::string, std::string>(" 1+2", "1 + 2", 14, clean_input);

  test_count += 1;
  test_passed +=
      run_good_test<std::string, std::string>("1+2 ", "1 + 2", 15, clean_input);

  test_count += 1;
  test_passed += run_good_test<std::string, std::string>(" 1+2 ", "1 + 2", 16,
                                                         clean_input);

  test_count += 1;
  test_passed += run_good_test<std::string, std::string>("  1+2", "1 + 2", 17,
                                                         clean_input);

  test_count += 1;
  test_passed += run_good_test<std::string, std::string>("1+2  ", "1 + 2", 18,
                                                         clean_input);

  test_count += 1;
  test_passed += run_good_test<std::string, std::string>("  1+2  ", "1 + 2", 19,
                                                         clean_input);

  std::cout << "Passed " << test_passed << " out of " << test_count << " tests."
            << std::endl;
}

void test_get_token_type() {
  int test_count = 0;
  int test_passed = 0;

  test_count += 1;
  test_passed += run_good_test<std::string, TokenType>("1", TokenType::OPERAND,
                                                       1, get_token_type);

  test_count += 1;
  test_passed += run_good_test<std::string, TokenType>(
      "000000", TokenType::OPERAND, 2, get_token_type);

  test_count += 1;
  test_passed += run_good_test<std::string, TokenType>(
      "123", TokenType::OPERAND, 3, get_token_type);

  test_count += 1;
  test_passed +=
      run_bad_test<std::string, TokenType>("1213a123", 4, get_token_type);

  test_count += 1;
  test_passed += run_bad_test<std::string, TokenType>("aa", 5, get_token_type);

  test_count += 1;
  test_passed +=
      run_bad_test<std::string, TokenType>("a123", 6, get_token_type);

  test_count += 1;
  test_passed += run_good_test<std::string, TokenType>("+", TokenType::OPERATOR,
                                                       7, get_token_type);

  test_count += 1;
  test_passed += run_good_test<std::string, TokenType>("*", TokenType::OPERATOR,
                                                       8, get_token_type);

  test_count += 1;
  test_passed += run_bad_test<std::string, TokenType>("", 9, get_token_type);

  test_count += 1;
  test_passed += run_bad_test<std::string, TokenType>(" ", 10, get_token_type);

  test_count += 1;
  test_passed += run_good_test<std::string, TokenType>(
      "123456789012345678901234567890", TokenType::OPERAND, 11, get_token_type);

  test_count += 1;
  test_passed +=
      run_bad_test<std::string, TokenType>("   ", 12, get_token_type);

  test_count += 1;
  test_passed +=
      run_bad_test<std::string, TokenType>("   123", 13, get_token_type);

  test_count += 1;
  test_passed +=
      run_bad_test<std::string, TokenType>("123   ", 14, get_token_type);

  test_count += 1;
  test_passed +=
      run_bad_test<std::string, TokenType>("   123   ", 15, get_token_type);

  std::cout << "Passed " << test_passed << " out of " << test_count << " tests"
            << std::endl;
}

void test_input_parser() {
  int test_count = 0;
  int test_passed = 0;

  test_count += 1;
  test_passed +=
      run_good_test<std::string>("1+2", "+", "1", "2", 1, input_parser);

  test_count += 1;
  test_passed +=
      run_good_test<std::string>("10*100", "*", "10", "100", 2, input_parser);

  test_count += 1;
  test_passed += run_bad_test<std::string>("1+", 3, input_parser);

  test_count += 1;
  test_passed += run_bad_test<std::string>("1 2", 4, input_parser);

  test_count += 1;
  test_passed += run_bad_test<std::string>("1++2", 5, input_parser);

  test_count += 1;
  test_passed += run_bad_test<std::string>("1+2+3", 6, input_parser);

  std::cout << "Passed " << test_passed << " out of " << test_count << " tests"
            << std::endl;
}

void test_add() {
  int test_count = 0;
  int test_passed = 0;

  test_count += 1;
  test_passed += run_good_test<std::string>("1", "2", "3", 1, add);

  test_count += 1;
  test_passed += run_good_test<std::string>("10", "100", "110", 2, add);

  test_count += 1;
  test_passed += run_good_test<std::string>("-10", "100", "90", 3, add);

  test_count += 1;
  test_passed += run_good_test<std::string>("10", "-100", "-90", 4, add);

  test_count += 1;
  test_passed += run_good_test<std::string>("-10", "-100", "-110", 5, add);

  test_count += 1;
  test_passed += run_good_test<std::string>("0", "0", "0", 6, add);

  test_count += 1;
  test_passed += run_good_test<std::string>("0", "100", "100", 7, add);

  test_count += 1;
  test_passed += run_good_test<std::string>("-10", "0", "-10", 8, add);

  test_count += 1;
  test_passed += run_good_test<std::string>("0", "-100", "-100", 9, add);

  test_count += 1;
  test_passed += run_good_test<std::string>("1234567890", "1234567890",
                                            "2469135780", 10, add);

  test_count += 1;
  test_passed +=
      run_good_test<std::string>("-1234567890", "1234567890", "0", 11, add);

  test_count += 1;
  test_passed += run_good_test<std::string>("1", "9", "10", 12, add);

  test_count += 1;
  test_passed += run_good_test<std::string>("2", "8", "10", 13, add);

  test_count += 1;
  test_passed += run_good_test<std::string>("2", "9", "11", 14, add);

  test_count += 1;
  test_passed += run_good_test<std::string>("3", "7", "10", 15, add);

  test_count += 1;
  test_passed += run_good_test<std::string>("3", "8", "11", 16, add);

  test_count += 1;
  test_passed += run_good_test<std::string>("3", "9", "12", 17, add);

  test_count += 1;
  test_passed += run_good_test<std::string>("4", "6", "10", 18, add);

  test_count += 1;
  test_passed += run_good_test<std::string>("4", "7", "11", 19, add);

  test_count += 1;
  test_passed += run_good_test<std::string>("4", "8", "12", 20, add);

  test_count += 1;
  test_passed += run_good_test<std::string>("4", "9", "13", 21, add);

  test_count += 1;
  test_passed += run_good_test<std::string>("5", "5", "10", 22, add);

  test_count += 1;
  test_passed += run_good_test<std::string>("5", "6", "11", 23, add);

  test_count += 1;
  test_passed += run_good_test<std::string>("5", "7", "12", 24, add);

  test_count += 1;
  test_passed += run_good_test<std::string>("5", "8", "13", 25, add);

  test_count += 1;
  test_passed += run_good_test<std::string>("5", "9", "14", 26, add);

  test_count += 1;
  test_passed += run_good_test<std::string>("6", "6", "12", 27, add);

  test_count += 1;
  test_passed += run_good_test<std::string>("6", "7", "13", 28, add);

  test_count += 1;
  test_passed += run_good_test<std::string>("6", "8", "14", 29, add);

  test_count += 1;
  test_passed += run_good_test<std::string>("6", "9", "15", 30, add);

  test_count += 1;
  test_passed += run_good_test<std::string>("7", "7", "14", 31, add);

  test_count += 1;
  test_passed += run_good_test<std::string>("7", "8", "15", 32, add);

  test_count += 1;
  test_passed += run_good_test<std::string>("7", "9", "16", 33, add);

  test_count += 1;
  test_passed += run_good_test<std::string>("8", "8", "16", 34, add);

  test_count += 1;
  test_passed += run_good_test<std::string>("8", "9", "17", 35, add);

  test_count += 1;
  test_passed += run_good_test<std::string>("9", "9", "18", 36, add);

  test_count += 1;
  test_passed += run_good_test<std::string>("99", "1", "100", 37, add);

  test_count += 1;
  test_passed += run_good_test<std::string>("1", "999", "1000", 38, add);

  test_count += 1;
  test_passed += run_good_test<std::string>("7654", "2346", "10000", 39, add);

  test_count += 1;
  test_passed +=
      run_good_test<std::string>("56678", "66778", "123456", 40, add);

  test_count += 1;
  test_passed += run_good_test<std::string>("1234567890", "9876543210",
                                            "11111111100", 41, add);

  test_count += 1;
  test_passed += run_good_test<std::string>(
      "63189762247395230376236159191975566013",
      "70107546393984562381126647999359202676",
      "133297308641379792757362807191334768689", 42, add);

  test_count += 1;
  test_passed += run_good_test<std::string>(
      "78265616672123476780099152293612406308",
      "25012031880538305104026878851169335106",
      "103277648552661781884126031144781741414", 43, add);

  test_count += 1;
  test_passed += run_good_test<std::string>(
      "635943644247062626553689081751154148350838819397516812131506860883040432"
      "971810962209446615629335223672223972364819603985480237058503088122793668"
      "01547870060909894054109590024095574203497613921030877739",
      "650552736520293918918251214904798396934738018277132334413629151074325567"
      "805472385461869994486906006667081987634830629165489973108669060550761181"
      "91666066678364492384118122385908779615747775693362034454",
      "128649638076735654547194029665595254528557683767464914654513601195736600"
      "077728334767131661011624123033930595999965023315097021016717214867355484"
      "993213936739274386438227712410004353819245389614392912193",
      44, add);

  test_count += 1;
  test_passed += run_good_test<std::string>("023482358374943", "23423434",
                                            "23482381798377", 45, add);

  test_count += 1;
  test_passed += run_good_test<std::string>("3243243", "0000324354254556",
                                            "324357497799", 46, add);

  test_count += 1;
  test_passed += run_good_test<std::string>("03413242343", "343243",
                                            "3413585586", 47, add);

  test_count += 1;
  test_passed += run_good_test<std::string>("00000954354352", "003545",
                                            "954357897", 48, add);

  test_count += 1;
  test_passed += run_good_test<std::string>("00023432454356434467897654",
                                            "00000000044343273454",
                                            "23432454356478811171108", 49, add);

  std::cout << "Passed " << test_passed << " out of " << test_count << " tests"
            << std::endl;
}

void test_digit_to_decimal() {
  int test_count = 0;
  int test_passed = 0;

  test_count += 1;
  test_passed += run_good_test<char, unsigned int>('1', 1, 1, digit_to_decimal);

  test_count += 1;
  test_passed += run_good_test<char, unsigned int>('2', 2, 2, digit_to_decimal);

  test_count += 1;
  test_passed += run_good_test<char, unsigned int>('3', 3, 3, digit_to_decimal);

  test_count += 1;
  test_passed += run_good_test<char, unsigned int>('4', 4, 4, digit_to_decimal);

  test_count += 1;
  test_passed += run_good_test<char, unsigned int>('5', 5, 5, digit_to_decimal);

  test_count += 1;
  test_passed += run_good_test<char, unsigned int>('6', 6, 6, digit_to_decimal);

  test_count += 1;
  test_passed += run_good_test<char, unsigned int>('7', 7, 7, digit_to_decimal);

  test_count += 1;
  test_passed += run_good_test<char, unsigned int>('8', 8, 8, digit_to_decimal);

  test_count += 1;
  test_passed += run_good_test<char, unsigned int>('9', 9, 9, digit_to_decimal);

  test_count += 1;
  test_passed +=
      run_good_test<char, unsigned int>('0', 0, 10, digit_to_decimal);

  std::cout << "Passed " << test_passed << " out of " << test_count << " tests"
            << std::endl;
}

void test_decimal_to_digit() {
  int test_count = 0;
  int test_passed = 0;

  test_count += 1;
  test_passed += run_good_test<unsigned int, char>(1, '1', 1, decimal_to_digit);

  test_count += 1;
  test_passed += run_good_test<unsigned int, char>(2, '2', 2, decimal_to_digit);

  test_count += 1;
  test_passed += run_good_test<unsigned int, char>(3, '3', 3, decimal_to_digit);

  test_count += 1;
  test_passed += run_good_test<unsigned int, char>(4, '4', 4, decimal_to_digit);

  test_count += 1;
  test_passed += run_good_test<unsigned int, char>(5, '5', 5, decimal_to_digit);

  test_count += 1;
  test_passed += run_good_test<unsigned int, char>(6, '6', 6, decimal_to_digit);

  test_count += 1;
  test_passed += run_good_test<unsigned int, char>(7, '7', 7, decimal_to_digit);

  test_count += 1;
  test_passed += run_good_test<unsigned int, char>(8, '8', 8, decimal_to_digit);

  test_count += 1;
  test_passed += run_good_test<unsigned int, char>(9, '9', 9, decimal_to_digit);

  test_count += 1;
  test_passed +=
      run_good_test<unsigned int, char>(0, '0', 10, decimal_to_digit);

  std::cout << "Passed " << test_passed << " out of " << test_count << " tests"
            << std::endl;
}

void test_trim_leading_zeros() {
  int test_count = 0;
  int test_passed = 0;

  test_count += 1;
  test_passed +=
      run_good_test<std::string, std::string>("", "", 1, trim_leading_zeros);

  test_count += 1;
  test_passed +=
      run_good_test<std::string, std::string>("0", "0", 2, trim_leading_zeros);

  test_count += 1;
  test_passed +=
      run_good_test<std::string, std::string>("1", "1", 3, trim_leading_zeros);

  test_count += 1;
  test_passed += run_good_test<std::string, std::string>("000", "0", 4,
                                                         trim_leading_zeros);

  test_count += 1;
  test_passed += run_good_test<std::string, std::string>("0001", "1", 5,
                                                         trim_leading_zeros);

  test_count += 1;
  test_passed += run_good_test<std::string, std::string>("000123", "123", 6,
                                                         trim_leading_zeros);

  test_count += 1;
  test_passed += run_good_test<std::string, std::string>("000123000", "123000",
                                                         7, trim_leading_zeros);

  test_count += 1;
  test_passed += run_good_test<std::string, std::string>(
      "0000001200003000000", "1200003000000", 8, trim_leading_zeros);

  test_count += 1;
  test_passed += run_good_test<std::string, std::string>(
      "0123000000000", "123000000000", 9, trim_leading_zeros);

  test_count += 1;
  test_passed += run_good_test<std::string, std::string>(
      "0000123000000000000", "123000000000000", 10, trim_leading_zeros);

  test_count += 1;
  test_passed += run_good_test<std::string, std::string>(
      "0000000000123000000000000000", "123000000000000000", 11,
      trim_leading_zeros);

  test_count += 1;
  test_passed += run_good_test<std::string, std::string>("-00123", "-123", 12,
                                                         trim_leading_zeros);

  test_count += 1;
  test_passed += run_good_test<std::string, std::string>("-00000", "0", 13,
                                                         trim_leading_zeros);

  test_count += 1;
  test_passed += run_good_test<std::string, std::string>(
      "-0000000000000000000326031034539696741651963735362758771645",
      "-326031034539696741651963735362758771645", 14, trim_leading_zeros);

  std::cout << "Passed " << test_passed << " out of " << test_count << " tests"
            << std::endl;
}

void test_remove_extra_whitespace() {
  int test_count = 0;
  int test_passed = 0;

  test_count += 1;
  test_passed += run_good_test<std::string, std::string>(
      "", "", 1, remove_extra_whitespace);

  test_count += 1;
  test_passed += run_good_test<std::string, std::string>(
      " ", "", 2, remove_extra_whitespace);

  test_count += 1;
  test_passed += run_good_test<std::string, std::string>(
      "\t", "", 3, remove_extra_whitespace);

  test_count += 1;
  test_passed += run_good_test<std::string, std::string>(
      "\n", "", 4, remove_extra_whitespace);

  test_count += 1;
  test_passed += run_good_test<std::string, std::string>(
      "a b c", "a b c", 5, remove_extra_whitespace);

  test_count += 1;
  test_passed += run_good_test<std::string, std::string>(
      "  a   b  c   ", "a b c", 6, remove_extra_whitespace);

  test_count += 1;
  test_passed += run_good_test<std::string, std::string>(
      "a\tb\n  c\td\n", "a b c d", 7, remove_extra_whitespace);

  test_count += 1;
  test_passed += run_good_test<std::string, std::string>(
      "   \t\n", "", 8, remove_extra_whitespace);

  test_count += 1;
  test_passed += run_good_test<std::string, std::string>(
      "  a b c   ", "a b c", 9, remove_extra_whitespace);

  test_count += 1;
  test_passed += run_good_test<std::string, std::string>(
      "a    \t   b    c", "a b c", 10, remove_extra_whitespace);

  test_count += 1;
  test_passed += run_good_test<std::string, std::string>(
      "a\t    b   \n c  \t\t d", "a b c d", 11, remove_extra_whitespace);

  test_count += 1;
  test_passed += run_good_test<std::string, std::string>(
      "a", "a", 12, remove_extra_whitespace);

  std::cout << "Passed " << test_passed << " out of " << test_count << " tests"
            << std::endl;
}

void test_add_extra_whitespace() {
  int test_count = 0;
  int test_passed = 0;

  test_count += 1;
  test_passed +=
      run_good_test<std::string, std::string>("", "", 1, add_extra_whitespace);

  test_count += 1;
  test_passed += run_good_test<std::string, std::string>(
      "hello world", "hello world", 2, add_extra_whitespace);

  test_count += 1;
  test_passed += run_good_test<std::string, std::string>("1+2", "1 + 2", 3,
                                                         add_extra_whitespace);

  test_count += 1;
  test_passed += run_good_test<std::string, std::string>("2*3", "2 * 3", 4,
                                                         add_extra_whitespace);

  test_count += 1;
  test_passed += run_good_test<std::string, std::string>(
      "1+2*3", "1 + 2 * 3", 5, add_extra_whitespace);

  test_count += 1;
  test_passed += run_good_test<std::string, std::string>(
      "1+2*3+4", "1 + 2 * 3 + 4", 6, add_extra_whitespace);

  test_count += 1;
  test_passed += run_good_test<std::string, std::string>(
      " 1 +2 *3 + 4 ", " 1  + 2  * 3  +  4 ", 7, add_extra_whitespace);

  test_count += 1;
  test_passed += run_good_test<std::string, std::string>(
      "1 + 2* 3", "1  +  2 *  3", 8, add_extra_whitespace);

  test_count += 1;
  test_passed += run_good_test<std::string, std::string>("2*", "2 * ", 9,
                                                         add_extra_whitespace);

  test_count += 1;
  test_passed += run_good_test<std::string, std::string>("5+", "5 + ", 10,
                                                         add_extra_whitespace);

  test_count += 1;
  test_passed += run_good_test<std::string, std::string>("6**7", "6 *  * 7", 11,
                                                         add_extra_whitespace);

  test_count += 1;
  test_passed += run_good_test<std::string, std::string>("8++9", "8 +  + 9", 12,
                                                         add_extra_whitespace);

  std::cout << "Passed " << test_passed << " out of " << test_count << " tests"
            << std::endl;
}

void test_multiply() {
  int test_count = 0;
  int test_passed = 0;

  test_count += 1;
  test_passed += run_good_test<std::string>("4", "2", "8", 1, multiply);

  test_count += 1;
  test_passed += run_good_test<std::string>("6", "7", "42", 2, multiply);

  test_count += 1;
  test_passed += run_good_test<std::string>("18", "51", "918", 3, multiply);

  test_count += 1;
  test_passed += run_good_test<std::string>("2", "73", "146", 4, multiply);

  test_count += 1;
  test_passed += run_good_test<std::string>("15", "29", "435", 5, multiply);

  test_count += 1;
  test_passed += run_good_test<std::string>("138", "3", "414", 6, multiply);

  test_count += 1;
  test_passed += run_good_test<std::string>("133", "193", "25669", 7, multiply);

  test_count += 1;
  test_passed += run_good_test<std::string>("175", "170", "29750", 8, multiply);

  test_count += 1;
  test_passed += run_good_test<std::string>("77", "185", "14245", 9, multiply);

  test_count += 1;
  test_passed +=
      run_good_test<std::string>("267", "310", "82770", 10, multiply);

  test_count += 1;
  test_passed += run_good_test<std::string>("97", "296", "28712", 11, multiply);

  test_count += 1;
  test_passed +=
      run_good_test<std::string>("426", "135", "57510", 12, multiply);

  test_count += 1;
  test_passed +=
      run_good_test<std::string>("462", "458", "211596", 13, multiply);

  test_count += 1;
  test_passed +=
      run_good_test<std::string>("340", "473", "160820", 14, multiply);

  test_count += 1;
  test_passed +=
      run_good_test<std::string>("650", "449", "291850", 15, multiply);

  test_count += 1;
  test_passed +=
      run_good_test<std::string>("201", "701", "140901", 16, multiply);

  test_count += 1;
  test_passed +=
      run_good_test<std::string>("409", "681", "278529", 17, multiply);

  test_count += 1;
  test_passed += run_good_test<std::string>("436", "10", "4360", 18, multiply);

  test_count += 1;
  test_passed += run_good_test<std::string>("65", "312", "20280", 19, multiply);

  test_count += 1;
  test_passed +=
      run_good_test<std::string>("826", "148", "122248", 20, multiply);

  test_count += 1;
  test_passed +=
      run_good_test<std::string>("835", "798", "666330", 21, multiply);

  test_count += 1;
  test_passed +=
      run_good_test<std::string>("92560376602614728379904026966926278813",
                                 "293714237838669943810821527929717135881",
                                 "271863004678972429954891312978348833473657956"
                                 "42144300771933294903095612389253",
                                 22, multiply);

  test_count += 1;
  test_passed +=
      run_good_test<std::string>("253967950181733959464222754977307541031",
                                 "180316957149263908158896046324419378557",
                                 "457947279902061133453794217306028065964444781"
                                 "30364571988565254524346799072267",
                                 23, multiply);

  test_count += 1;
  test_passed +=
      run_good_test<std::string>("21908053698591430889884716219790042707",
                                 "247522227375530822504869309591812499731",
                                 "542273024893808716189374096152826182081796241"
                                 "0320109849009085449412916011817",
                                 24, multiply);

  test_count += 1;
  test_passed +=
      run_good_test<std::string>("312593134826879571846277171194994747988",
                                 "127933071689708753625542069154374107141",
                                 "399909999275179783868075151704966436501033957"
                                 "52038355272585625400831806182308",
                                 25, multiply);

  test_count += 1;
  test_passed +=
      run_good_test<std::string>("277107227223263068869006447385503119506",
                                 "36994405250675160944990517366391207319",
                                 "102514170617883181744944439926971971878417678"
                                 "49485878284657263576044078864414",
                                 26, multiply);

  test_count += 1;
  test_passed += run_good_test<std::string>(
      "319264486160301610623130906535299997565299282011342708185667537181062793"
      "393925818736355680418672802280648004783526266207147205659978073091704120"
      "69757651406512292671358960177620284797469567026042358307",
      "871304908686793552282408735936531804573590552620959447081787843398985090"
      "224665704004522228569803679765570260471580268526056005150679101835852618"
      "3993460162719227906293532683974393287134969979655939688",
      "278176713960837658663890361707834302225900368302779976454145525707051491"
      "142506255050156864600090842289913664391813773982051355900704279125698119"
      "109099741333434911416154392632385818969364477731069091485254307359453846"
      "509441412604786448355696920337561777234363813013089625094690648072718812"
      "358384314679026194446472804240640443218537208868169681894895852507781489"
      "128474436700156845647363577935677788216",
      27, multiply);

  test_count += 1;
  test_passed += run_good_test<std::string>("068742343", "996854",
                                            "68526079588922", 28, multiply);

  test_count += 1;
  test_passed += run_good_test<std::string>("12344", "000000057683583",
                                            "712046148552", 29, multiply);

  test_count += 1;
  test_passed +=
      run_good_test<std::string>("0024443", "8988", "219693684", 30, multiply);

  test_count += 1;
  test_passed += run_good_test<std::string>("000003434", "0765865",
                                            "2629980410", 31, multiply);

  test_count += 1;
  test_passed += run_good_test<std::string>("386894", "00034343", "13287100642",
                                            32, multiply);

  test_count += 1;
  test_passed += run_good_test<std::string>("000068745345", "00000001",
                                            "68745345", 33, multiply);

  test_count += 1;
  test_passed += run_good_test<std::string>("-4", "2", "-8", 34, multiply);

  test_count += 1;
  test_passed += run_good_test<std::string>("4", "-2", "-8", 35, multiply);

  test_count += 1;
  test_passed += run_good_test<std::string>("-4", "-2", "8", 36, multiply);

  test_count += 1;
  test_passed +=
      run_good_test<std::string>("-123", "456", "-56088", 37, multiply);

  test_count += 1;
  test_passed +=
      run_good_test<std::string>("123", "-456", "-56088", 38, multiply);

  test_count += 1;
  test_passed +=
      run_good_test<std::string>("-123", "-456", "56088", 39, multiply);

  test_count += 1;
  test_passed += run_good_test<std::string>("0", "-123", "0", 40, multiply);

  test_count += 1;
  test_passed += run_good_test<std::string>("-123", "0", "0", 41, multiply);

  test_count += 1;
  test_passed += run_good_test<std::string>("-123", "1", "-123", 42, multiply);

  test_count += 1;
  test_passed += run_good_test<std::string>("1", "-123", "-123", 43, multiply);

  test_count += 1;
  test_passed += run_good_test<std::string>(
      "632194879321698326498732184697693218796487632914862938749621364932176",
      "0", "0", 44, multiply);

  test_count += 1;
  test_passed += run_good_test<std::string>(
      "632194879321698326498732184697693218796487632914862938749621364932176",
      "1",
      "632194879321698326498732184697693218796487632914862938749621364932176",
      45, multiply);

  test_count += 1;
  test_passed += run_good_test<std::string>(
      "632194879321698326498732184697693218796487632914862938749621364932176",
      "-1",
      "-632194879321698326498732184697693218796487632914862938749621364932176",
      46, multiply);

  test_count += 1;
  test_passed += run_good_test<std::string>(
      "632194879321698326498732184697693218796487632914862938749621364932176",
      "999999999999999999999999999999999999999999999999999999999999999",
      "632194879321698326498732184697693218796487632914862938749621364299981120"
      "678301673501267815302306781203512367085137061250378635067824",
      47, multiply);

  test_count += 1;
  test_passed += run_good_test<std::string>(
      "-632194879321698326498732184697693218796487632914862938749621364932176",
      "-999999999999999999999999999999999999999999999999999999999999999",
      "632194879321698326498732184697693218796487632914862938749621364299981120"
      "678301673501267815302306781203512367085137061250378635067824",
      48, multiply);

  test_count += 1;
  test_passed +=
      run_good_test<std::string>("00012312312", "2", "24624624", 49, multiply);

  test_count += 1;
  test_passed += run_good_test<std::string>("00012312312", "-2", "-24624624",
                                            50, multiply);

  test_count += 1;
  test_passed += run_good_test<std::string>("00012312312", "000045",
                                            "554054040", 51, multiply);

  test_count += 1;
  test_passed += run_good_test<std::string>(
      "000000000632194879321698326498732184697693218796487632914862938749621364"
      "932176",
      "999999999999999999999999999999999999999999999999999999999999999",
      "632194879321698326498732184697693218796487632914862938749621364299981120"
      "678301673501267815302306781203512367085137061250378635067824",
      52, multiply);

  test_count += 1;
  test_passed += run_good_test<std::string>("-00012312312", "0000045",
                                            "-554054040", 53, multiply);

  test_count += 1;
  test_passed += run_good_test<std::string>(
      "00063219487932169832649873218469769321879648763291486293874962136493217"
      "6",
      "-0000000000000000000000000000000000000000000000000000000000000000001",
      "-632194879321698326498732184697693218796487632914862938749621364932176",
      54, multiply);

  std::cout << "Passed " << test_passed << " out of " << test_count << " tests"
            << std::endl;
}

void test_subract() {
  int test_count = 0;
  int test_passed = 0;

  test_count += 1;
  test_passed += run_good_test<std::string>("5", "3", "2", 1, subtract);

  test_count += 1;
  test_passed += run_good_test<std::string>("-5", "3", "-8", 2, subtract);

  test_count += 1;
  test_passed += run_good_test<std::string>("5", "-3", "8", 3, subtract);

  test_count += 1;
  test_passed += run_good_test<std::string>("-5", "-3", "-2", 4, subtract);

  test_count += 1;
  test_passed += run_good_test<std::string>(
      "123456789123456789", "123456789123456788", "1", 5, subtract);

  test_count += 1;
  test_passed +=
      run_good_test<std::string>("123456789123456789", "-123456789123456788",
                                 "246913578246913577", 6, subtract);

  test_count += 1;
  test_passed +=
      run_good_test<std::string>("-123456789", "-123456788", "-1", 7, subtract);

  test_count += 1;
  test_passed += run_good_test<std::string>("0", "0", "0", 8, subtract);

  test_count += 1;
  test_passed += run_good_test<std::string>("123", "0", "123", 9, subtract);

  test_count += 1;
  test_passed += run_good_test<std::string>("0", "123", "-123", 10, subtract);

  test_count += 1;
  test_passed += run_good_test<std::string>("123", "456", "-333", 11, subtract);

  test_count += 1;
  test_passed +=
      run_good_test<std::string>("-123", "-456", "333", 12, subtract);

  test_count += 1;
  test_passed +=
      run_good_test<std::string>("-123", "456", "-579", 13, subtract);

  test_count += 1;
  test_passed += run_good_test<std::string>(
      "123456789123456789", "123456789123456788", "1", 14, subtract);

  test_count += 1;
  test_passed +=
      run_good_test<std::string>("123456789123456789", "-123456789123456788",
                                 "246913578246913577", 15, subtract);

  test_count += 1;
  test_passed += run_good_test<std::string>("-123456789", "-123456788", "-1",
                                            16, subtract);

  test_count += 1;
  test_passed += run_good_test<std::string>(
      "987654321098765432109876543210987654321",
      "987654321098765432109876543210987654321", "0", 17, subtract);

  test_count += 1;
  test_passed += run_good_test<std::string>(
      "-987654321098765432109876543210987654321",
      "-987654321098765432109876543210987654321", "0", 18, subtract);

  std::cout << "Passed " << test_passed << " out of " << test_count << " tests"
            << std::endl;
}
