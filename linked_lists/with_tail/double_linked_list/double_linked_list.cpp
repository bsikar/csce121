#include "double_linked_list.h"
#include <iostream>

DoubleLinkedList::DoubleLinkedList() : head(nullptr), tail(nullptr), size(0) {}
DoubleLinkedList::~DoubleLinkedList() { clear(); }

DoubleLinkedList::DoubleLinkedList(const DoubleLinkedList &other)
    : head(other.head), tail(other.tail), size(other.size) {}

DoubleLinkedList &DoubleLinkedList::operator=(const DoubleLinkedList &other) {
  head = other.head;
  tail = other.tail;
  size = other.size;
  return *this;
}

int DoubleLinkedList::prepend(int value) { return insert(0, value); }
int DoubleLinkedList::append(int value) { return insert(size, value); }
bool DoubleLinkedList::is_empty() const { return size == 0; }

int DoubleLinkedList::get(int index) const {
  Node *node = head;
  for (int i = 0; node != nullptr; i++) {
    if (i == index) {
      return node->data;
    }
    node = node->next;
  }
  throw std::runtime_error("Invalid index");
}

int DoubleLinkedList::set(int index, int value) {
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

int DoubleLinkedList::length() const { return size; }

std::string DoubleLinkedList::print() const {
  std::string output;
  Node *node = head;
  while (node != nullptr) {
    output += std::to_string(node->data) + " ";
    node = node->next;
  }

  return output;
}

void DoubleLinkedList::clear() {
  Node *curr = head;
  while (curr != nullptr) {
    Node *next = curr->next;
    delete curr;
    curr = next;
  }
  head = nullptr;
}

int DoubleLinkedList::find(int value) const {
  Node *node = head;
  for (int i = 0; node != nullptr; i++) {
    if (head->data == value) {
      return i;
    }
    node = node->next;
  }
  return -1;
}

int DoubleLinkedList::remove(int value) {
  Node *node = head;
  for (int i = 0; node != nullptr; i++) {
    if (node->data == value) {
      return remove_at(i);
    }
    node = node->next;
  }
  return -1;
}

int DoubleLinkedList::remove_at(int index) {
  Node *node = head;
  for (int i = 0; node != nullptr; i++) {
    if (i == index) {
      int value = node->data;
      if (node == head) {
        head = node->next;
        if (head != nullptr) {
          head->prev = nullptr;
        }
      } else {
        node->prev->next = node->next;
        if (node->next != nullptr) {
          node->next->prev = node->prev;
        }
      }
      delete node;
      return value;
    }
    node = node->next;
  }
  throw std::runtime_error("Invalid index");
}

void DoubleLinkedList::reverse() {
  Node *temp = nullptr;
  Node *node = head;

  while (node != nullptr) {
    temp = node->prev;
    node->prev = node->next;
    node->next = temp;
    node = node->prev;
  }

  if (temp != nullptr) {
    head = temp->prev;
  }
}

int DoubleLinkedList::insert(int index, int value) {
  if (index < 0 || index > size) {
    return -1;
  }

  Node *new_node = new Node(value);
  if (index == 0) {
    new_node->next = head;
    head = new_node;
    if (tail == nullptr) {
      tail = new_node;
    }
    size += 1;
    return index;
  }

  if (index == size) {
    tail->next = new_node;
    new_node->prev = tail;
    tail = new_node;
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
  new_node->prev = prev;
  new_node->next = curr;
  curr->prev = new_node;
  size += 1;
  return index;
}

void DoubleLinkedList::sort() {
  Node *curr = head;
  Node *next = nullptr;

  while (curr != nullptr) {
    next = curr->next;
    while (next != nullptr) {
      if (curr->data > next->data) {
        int temp = curr->data;
        curr->data = next->data;
        next->data = temp;
      }
      next = next->next;
    }
    curr = curr->next;
  }
}

std::ostream &operator<<(std::ostream &os, const DoubleLinkedList &list) {
  os << list.print();
  return os;
}
