// Good Tests

// 1 input
template <typename A, typename U>
unsigned int run_good_test(A input, U expected, unsigned int test_num,
                           U (*func)(A));

// 2 input
template <typename A, typename B, typename U>
unsigned int run_good_test(A input1, B input2, U expected,
                           unsigned int test_num, U (*func)(A, B));

// 3 input
template <typename A, typename B, typename C, typename U>
unsigned int run_good_test(A input1, B input2, C input3, U expected,
                           unsigned int test_num, U (*func)(A, B, C));

// 4 input
template <typename A, typename B, typename C, typename D, typename U>
unsigned int run_good_test(A input1, B input2, C input3, D input4, U expected,
                           unsigned int test_num, U (*func)(A, B, C, D));

// 5 input
template <typename A, typename B, typename C, typename D, typename E,
          typename U>
unsigned int run_good_test(A input1, B input2, C input3, D input4, E input5,
                           U expected, unsigned int test_num,
                           U (*func)(A, B, C, D, E));

// 6 input
template <typename A, typename B, typename C, typename D, typename E,
          typename F, typename U>
unsigned int run_good_test(A input1, B input2, C input3, D input4, E input5,
                           F input6, U expected, unsigned int test_num,
                           U (*func)(A, B, C, D, E, F));

// Bad Tests
// 1 input
template <typename A, typename U>
unsigned int run_good_test(A input, unsigned int test_num, U (*func)(A));

// 2 input
template <typename A, typename B, typename U>
unsigned int run_good_test(A input1, B input2, unsigned int test_num,
                           U (*func)(A, B));

// 3 input
template <typename A, typename B, typename C, typename U>
unsigned int run_good_test(A input1, B input2, C input3, unsigned int test_num,
                           U (*func)(A, B, C));

// 4 input
template <typename A, typename B, typename C, typename D, typename U>
unsigned int run_good_test(A input1, B input2, C input3, D input4,
                           unsigned int test_num, U (*func)(A, B, C, D));

// 5 input
template <typename A, typename B, typename C, typename D, typename E,
          typename U>
unsigned int run_good_test(A input1, B input2, C input3, D input4, E input5,
                           unsigned int test_num, U (*func)(A, B, C, D, E));

// 6 input
template <typename A, typename B, typename C, typename D, typename E,
          typename F, typename U>
unsigned int run_good_test(A input1, B input2, C input3, D input4, E input5,
                           F input6, unsigned int test_num,
                           U (*func)(A, B, C, D, E, F));
