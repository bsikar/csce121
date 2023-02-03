#ifndef FUNCTIONS_H
#define FUNCTIONS_H

/**
 * @brief Determines if a range defined by two integers is valid.
 *
 * @param a The lower bound of the range.
 * @param b The upper bound of the range.
 *
 * @return True if the range is valid, false otherwise. A range is considered
 * valid if `a >= 10`, `b < 10000`, and `a <= b`.
 */
bool is_valid_range(int a, int b);

/**
 * @brief Calculates the number of digits in an integer.
 *
 * @param n The integer to find the number of digits for.
 *
 * @return The number of digits in the integer.
 */
int num_len(int n);

/**
 * @brief Converts an integer into an array of its digits.
 *
 * @param n The integer to convert.
 *
 * @return A dynamically allocated array of integers, representing the digits of
 * the input integer. The caller is responsible for freeing the memory of the
 * returned array.
 */
int *int_to_arr(int n);

/**
 * @brief Determines if a pair of integers is increasing.
 *
 * @param a The first integer.
 * @param b The second integer.
 *
 * @return True if `b > a`, false otherwise.
 */
bool is_increasing(int a, int b);

/**
 * @brief Classifies if a number represents a Mountain, Vallery, or Neither.
 *
 * 'M' means Mountain, 'V' means Valley, and 'N' means Neither.
 *
 * @param number The number to classify.
 *
 * @return 'M', 'V', or 'N' depending on the type of the number.
 */
char classify_mv_range_type(int number);

/**
 * @brief Function to count the number of valid mountain and valley ranges
 * between a and b and return prints the count of mountain and valley ranges
 *
 * @param a Starting range
 * @param b Ending range
 */
void count_valid_mv_numbers(int a, int b);

#endif // FUNCTIONS_H
