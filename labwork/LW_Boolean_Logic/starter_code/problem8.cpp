#include <iostream>

bool f(bool a, bool b, bool c) {
  return !a && c || !a && b || b && c || a && !b && !c;
}
