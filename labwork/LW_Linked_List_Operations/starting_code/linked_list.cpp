#include "linked_list.h"
#include <iostream>
#include <string>

using std::cout, std::endl, std::string, std::ostream;

void MyList::add(const std::string &name, int score) {
  MyNode *node = new MyNode(name, score);

  if (_head == nullptr) {
    _head = node;
    _tail = node;
    _size += 1;
    return;
  }

  _tail->next = node;
  node->prev = _tail;
  _tail = node;
  _size += 1;
}

void MyList::clear() {
  MyNode *node = _head;
  while (node != nullptr) {
    MyNode *next = node->next;
    delete node;
    node = next;
  }
  _head = nullptr;
  _tail = nullptr;
  _size = 0;
}

bool MyList::remove(const std::string &name) {
  MyNode *node = _head;
  while (node != nullptr) {
    // check this is the node we want
    if (node->name == name) {
      if (node->prev != nullptr) {
        node->prev->next = node->next;
      } else {
        _head = node->next;
      }
      if (node->next != nullptr) {
        node->next->prev = node->prev;
      } else {
        _tail = node->prev;
      }
      delete node;
      _size -= 1;
      return true;
    }
    // get next node
    node = node->next;
  }
  return false;
}

bool MyList::insert(const std::string &name, int score, size_t index) {
  if (index > _size) {
    return false;
  }
  MyNode *new_node = new MyNode(name, score);
  // if the head is null
  if (_head == nullptr) {
    _head = new_node;
    _tail = new_node;
    _size += 1;
    return true;
  }

  // if we are adding to the front
  if (index == 0) {
    new_node->next = _head;
    new_node->prev = nullptr;
    _head->prev = new_node;
    _head = new_node;
    _size += 1;
    return true;
  }

  MyNode *curr_node = _head;
  for (size_t i = 0; i < index - 1; i++) {
    curr_node = curr_node->next;
  }

  // swap the values around
  new_node->next = curr_node->next;
  if (curr_node->next !=nullptr) {
    curr_node->next->prev = new_node;
  } else {
    curr_node->next = nullptr;
  }
  curr_node->next = new_node;
  new_node->prev = curr_node;

  // check for nullcase
  if (new_node->next != nullptr) {
    new_node->next->prev = new_node;
  } else {
    _tail = new_node;
  }
  _size += 1;
  return true;
}

MyList::MyList() : _size(0), _head(nullptr), _tail(nullptr) {}

MyList::~MyList() { clear(); }

size_t MyList::size() const { return _size; }

bool MyList::empty() const { return _head == nullptr; }

MyNode *MyList::head() const { return _head; }

ostream &operator<<(ostream &os, const MyList &myList) {
  MyNode *_current = myList.head();
  if (_current == nullptr) {
    os << "<empty>" << endl;
    return os;
  }

  os << "[ " << _current->name << ", " << _current->score << " ]";
  _current = _current->next;
  while (_current != nullptr) {
    os << " --> [ " << _current->name << ", " << _current->score << " ]";
    _current = _current->next;
  }

  return os;
}

MyNode::MyNode(const std::string &name, int score)
    : name(name), score(score), next(nullptr), prev(nullptr) {}

MyNode::MyNode(const MyNode &other)
    : name(other.name), score(other.score), next(other.next), prev(other.prev) {
}
MyNode &MyNode::operator=(const MyNode &other) {
  name = other.name;
  score = other.score;
  next = other.next;
  prev = other.prev;
  return *this;
}
MyList::MyList(const MyList &other)
    : _size(other._size), _head(other._head), _tail(other._tail) {}

MyList &MyList::operator=(const MyList &other) {
  _size = other._size;
  _head = other._head;
  _tail = other._tail;
  return *this;
}

void MyList::print() {
  MyNode *node = _head;
  while (node != nullptr) {
    cout << node->name << " " << node->score << endl;
    node = node->next;
  }
}
