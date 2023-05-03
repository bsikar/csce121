#include "single_linked_list/single_linked_list.h"
#include <iostream>

int main(int argc, char **argv) {
  SingleLinkedList list = SingleLinkedList();
  for (int i = 0; i < 10; i++) {
    list.append(i);
  }
  std::cout << list.length() << std::endl;
  std::cout << list << std::endl;
  list.reverse();
  std::cout << list << std::endl;

  return 0;
}
