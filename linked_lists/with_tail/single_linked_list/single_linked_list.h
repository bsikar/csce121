#ifndef SINGLE_LINKED_LIST
#define SINGLE_LINKED_LIST

#include <iostream>

class SingleLinkedList {
private:
  struct Node {
    int data;
    Node *next;

    Node() : data(0), next(nullptr) {}
    Node(int data) : data(data), next(nullptr) {}
  };
  Node *head;
  Node *tail;
  int size;

public:
  SingleLinkedList();
  SingleLinkedList(const SingleLinkedList &other);
  SingleLinkedList &operator=(const SingleLinkedList &other);
  ~SingleLinkedList();
  int remove(int value);  // returns the index it was removed from
  int prepend(int value); // adds to the front of the list (returns 0)
  int append(int value);  // adds to the end of the list (returns len-1)
  int insert(int index, int value); // returns the index it was added to
  int get(int index) const;         // returns the value at the index
  int set(int index, int value);    // returns the old value at the index
  int length() const;               // returns the length of the list
  std::string print() const;        // prints the list
  void clear();                     // clears the list
  int remove_at(int index);         // returns value removed at the index
  int find(int value) const;        // returns index of value
  bool is_empty() const;            // returns if its empty
  void reverse();                   // reverses the list
  void sort();                      // sorts the list
};

std::ostream &operator<<(std::ostream &os, const SingleLinkedList &list);

#endif
