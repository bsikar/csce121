#include "single_linked_list.h"
#include <iostream>

SingleLinkedList::SingleLinkedList() : head(nullptr), size(0) {}
SingleLinkedList::~SingleLinkedList() { clear(); }
int SingleLinkedList::prepend(int value) { return insert(0, value); }
int SingleLinkedList::append(int value) { return insert(size, value); }
bool SingleLinkedList::is_empty() const { return size == 0; }

int SingleLinkedList::get(int index) const {
  Node *node = head;
  for (int i = 0; node != nullptr; i++) {
    if (i == index) {
      return node->data;
    }
    node = node->next;
  }
  throw std::runtime_error("Invalid index");
}

int SingleLinkedList::set(int index, int value) {
  Node *node = head;
  for (int i = 0; node != nullptr; i++) {
    if (i == index) {
      int old_value = node->data;
      node->data = value;
      return old_value;
    }
    node = node->next;
  }
  throw std::runtime_error("Invalid index");
}

int SingleLinkedList::length() const { return size; }

std::string SingleLinkedList::print() const {
  std::string output;
  Node *node = head;
  while (node != nullptr) {
    output += std::to_string(node->data) + " ";
    node = node->next;
  }

  return output;
}

void SingleLinkedList::clear() {
  Node *curr = head;
  while (curr != nullptr) {
    Node *next = curr->next;
    delete curr;
    curr = next;
  }
  head = nullptr;
}

int SingleLinkedList::find(int value) const {
  Node *node = head;
  for (int i = 0; node != nullptr; i++) {
    if (head->data == value) {
      return i;
    }
    node = node->next;
  }
  return -1;
}

int SingleLinkedList::remove(int value) {
  Node *node = head;
  for (int i = 0; node != nullptr; i++) {
    if (node->data == value) {
      return remove_at(i);
    }
    node = node->next;
  }
  return -1;
}

int SingleLinkedList::remove_at(int index) {
  Node *prev = head;
  Node *curr = head->next;
  for (int i = 0; curr != nullptr; i++) {
    if (i == index) {
      prev->next = curr->next;
      int value = curr->data;
      delete curr;
      curr = nullptr;
      size -= 1;
      return value;
    }
    prev = curr;
    curr = curr->next;
  }
  throw std::runtime_error("Invalid index");
}

void SingleLinkedList::reverse() {
  Node *prev = nullptr;
  Node *curr = head;
  Node *next = nullptr;

  while (curr != nullptr) {
    next = curr->next;
    curr->next = prev;
    prev = curr;
    curr = next;
  }

  head = prev;
}

int SingleLinkedList::insert(int index, int value) {
  if (index < 0 || index > size) {
    return -1;
  }

  Node *new_node = new Node(value);

  if (index == 0) {
    new_node->next = head;
    head = new_node;
    size += 1;
    return index;
  }

  Node *prev = nullptr;
  Node *curr = head;
  for (int i = 0; i < index; i++) {
    prev = curr;
    curr = curr->next;
  }
  prev->next = new_node;
  new_node->next = curr;
  size += 1;
  return index;
}

void SingleLinkedList::sort() {}

std::ostream &operator<<(std::ostream &os, const SingleLinkedList &list) {
  os << list.print();
  return os;
}
