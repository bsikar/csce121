#ifndef STRING_CALCULATOR_H
#define STRING_CALCULATOR_H

#include <iostream>
#include <string>

// an operator is : + or *
// an operand is any digit
enum class TokenType { OPERATOR, OPERAND };

/*
Returns a string with extra whitespace added between operators and operands and
removed from the beginning and end of the string input: a string output: a
cleaned string throws: none
*/
std::string clean_input(const std::string &input);

/*
Adds extra whitespace around operators so that they can be easily
tokenized later.
input: a string containing an expression
output: a string with extra whitespace around operators
throws: none
*/
std::string add_extra_whitespace(const std::string &);

/*
Removes extra whitespace from a string
input: a string containing an expression
output: a string with extra whitespace removed
throws: none
*/
std::string remove_extra_whitespace(const std::string &);

/*
Overload the stream insertion operator to print a TokenType enum value
input: an output stream and a TokenType enum value
output: an output stream with the corresponding string representation of
the TokenType appended to it
throw: none
*/
std::ostream &operator<<(std::ostream &, const TokenType &);

/*
Determine if a token is an operator or an operand
input: a string (token)
output: a TokenType
throw: std::invalid_argument if the token is not an operator or an operand
*/
TokenType get_token_type(const std::string &);

/*
convert a string into an array of strings, indexes 1 and 2 are the operands and
index 0 is the operator
input: string - the string to parse
output: string[] - the array of strings
throws: std::invalid_argument - if the string is not a valid expression

user is responsible for freeing the memory allocated for the array
*/
std::string *input_parser(std::string &);

/*
calculate the result of an expression
input: 2 operands and an operator as an array
output: string - the result of the expression
throws: std::invalid_argument - if the string is not a valid expression
*/
std::string calculate(const std::string *);

/*
convert a character digit to an integer value
input: digit - a character representing a digit, e.g. '7'
output: the corresponding integer value of the digit, e.g. 7
throws: std::invalid_argument if the input is not a valid digit, e.g. '0' -- '9'
*/
unsigned int digit_to_decimal(char digit);

/*
convert an integer value to a character digit
input: decimal - an integer value of a digit, e.g. 7
output: the corresponding character of the digit, e.g. '7'
throws: std::invalid_argument if the input is not a valid digit, e.g. 0 -- 9
*/
char decimal_to_digit(unsigned int decimal);

/*
remove the leading zeros from a number
input: num - a string representing a number with zero or more leading 0s
output: a copy of the input with all leading 0s removed
throws: none
*/
std::string trim_leading_zeros(const std::string &num);

/*
add two numbers
input: lhs,rhs - strings representing numbers, e.g. "1", "2"
output: the result of adding rhs to lhs: lhs + rhs e.g. "3"
throws: none.
*/
std::string add(const std::string &lhs, const std::string &rhs);

/*
muplity two numbers
input: lhs,rhs - strings representing numbers, e.g. "1", "2"
output: the result of multiplying lhs by rhs: lhs * rhs, e.g. "2"
throws:  none.
*/
std::string multiply(const std::string &lhs, const std::string &rhs);

#endif // STRING_CALCULATOR_H
