#include "LinkedList.h"
#include "Node.h"
#include <iostream>
#include <sstream>
#include <string>

using std::string, std::ostream;

LinkedList::LinkedList() : head(nullptr), tail(nullptr) {}

LinkedList::~LinkedList() { clear(); }

LinkedList::LinkedList(const LinkedList &source)
    : head(source.head), tail(source.tail) {}

LinkedList &LinkedList::operator=(const LinkedList &source) {
  head = source.head;
  tail = source.tail;
  return *this;
}

void LinkedList::insert(string location, int year, int month,
                        double temperature) {
  Node *new_node = new Node(location, year, month, temperature);

  if (head == nullptr) {
    head = new_node;
    tail = new_node;
    return;
  }

  if (new_node->data < head->data) {
    new_node->next = head;
    head = new_node;
    return;
  }

  Node *curr_node = head->next;
  Node *prev_node = head;

  while (curr_node != nullptr && curr_node->data < new_node->data) {
    prev_node = curr_node;
    curr_node = curr_node->next;
  }

  if (curr_node == nullptr) {
    tail->next = new_node;
    tail = new_node;
  } else {
    prev_node->next = new_node;
    new_node->next = curr_node;
  }
}

void LinkedList::clear() {
  Node *current = head;
  while (current != nullptr) {
    Node *next = current->next;
    delete current;
    current = next;
  }
  head = nullptr;
  tail = nullptr;
}

Node *LinkedList::getHead() const { return head; }

string LinkedList::print() const {
  string output;

  Node *node = head;
  while (node != nullptr) {
    TemperatureData data = node->data;
    std::ostringstream os;
    os.precision(2);
    os << std::fixed << data.temperature;
    std::string temp = os.str();
    temp.erase(temp.find_last_not_of('0') + 1, std::string::npos);
    if (temp[temp.length() - 1] == '.') {
      temp = temp.substr(0, temp.length() - 1);
    }

    output += data.id + " " + std::to_string(data.year) + " " +
              std::to_string(data.month) + " " + temp + "\n";

    node = node->next;
  }
  return output;
}

ostream &operator<<(ostream &os, const LinkedList &ll) {
  os << ll.print();
  return os;
}
