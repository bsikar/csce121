#include "functions.h"
using std::cin, std::cout, std::endl, std::ostream, std::string;

#define INFO(X)                                                                \
  cout << "[INFO] (" << __FUNCTION__ << ":" << __LINE__ << ") " << #X << " = " \
       << X << endl;
#define INFO_STRUCT(X)                                                         \
  cout << "[INFO] (" << __FUNCTION__ << ":" << __LINE__ << ") " << #X          \
       << " count = " << X.count << endl;

/**
 * ----- REQUIRED -----
 * Pushes number to top of stack. If stack is full, then resize stack's array.
 * @param   stack   Target stack.
 * @param   number  Number to push to stack.
 */
void push(Stack &stack, int number) {
  // INFO_STRUCT(stack);
  // INFO(number);
  //   check if the stack is full
  if (stack.capacity == stack.count) {
    int *numbers = new int[stack.capacity * 2];
    for (int i = 0; i < stack.count; i++) {
      numbers[i] = stack.numbers[i];
    }
    delete[] stack.numbers;
    stack.numbers = numbers;
    stack.capacity *= 2;
  }
  // push number to stack
  stack.numbers[stack.count] = number;
  stack.count += 1;
}

/**
 * ----- REQUIRED -----
 * Pops number from top of stack. If stack is empty, then return 0.
 * @param   stack   Target stack.
 * @return  Number from top of stack.
 */
int pop(Stack &stack) {
  // INFO_STRUCT(stack);
  //  check if the stack is empty
  if (stack.count == 0) {
    return INT32_MAX;
  }

  stack.count -= 1;
  int number = stack.numbers[stack.count];

  // check if its too small
  if (stack.count <= stack.capacity / 4) {
    int capacity = stack.capacity / 2;
    // the value could be 0
    if (capacity < 1) {
      capacity = 1;
    }

    int *numbers = new int[capacity];
    for (int i = 0; i < stack.count; i++) {
      numbers[i] = stack.numbers[i];
    }
    delete[] stack.numbers;
    stack.numbers = numbers;
  }
  return number;
}

/**
 * ----- OPTIONAL -----
 * Returns the number at top of stack without popping it. If stack is empty,
 * return INT32_MAX.
 * @param   stack   Target statck.
 * @return          Number at top of stack.
 */
int peek(const Stack &stack) {
  // TODO (optional): implement peek function for stack
  // INFO_STRUCT(stack);
  if (stack.count == 0) {
    return INT32_MAX;
  }
  return stack.numbers[stack.count - 1];
}
