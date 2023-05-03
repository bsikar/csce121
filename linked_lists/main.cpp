#include "no_tail/double_linked_list/double_linked_list.h"
#include "no_tail/single_linked_list/single_linked_list.h"
#include <iostream>

int main() {
  SingleLinkedList list = SingleLinkedList();
  for (int i = 0; i < 10; i++) {
    list.append(i);
  }
  std::cout << list.length() << std::endl;
  std::cout << list << std::endl;
  list.reverse();
  std::cout << list << std::endl;

  DoubleLinkedList dlist = DoubleLinkedList();
  for (int i = 10; i < 20; i++) {
    dlist.append(i);
  }
  std::cout << dlist.length() << std::endl;
  std::cout << dlist << std::endl;
  dlist.reverse();
  std::cout << dlist << std::endl;

  return 0;
}
