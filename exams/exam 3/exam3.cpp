#include <iostream>

using namespace std;

/***************************************
 * QUESTION 1
 */

class AllocatorFloat {
private:
  float **mem;
  int size;
  int capacity;

  void resize();

public:
  AllocatorFloat() : mem(nullptr), size(0), capacity(0) {}
  ~AllocatorFloat();
  AllocatorFloat(const AllocatorFloat &other);
  AllocatorFloat &operator=(const AllocatorFloat &other);

  void clear();
  const float *operator[](int val);
  const void printAllocator();
  const int getSize() const { return size; }

  // Q2.1
  float *giveFloat(float val);

  // Q2.2
};

const float *AllocatorFloat::operator[](int val) {
  if (val < 0 || val >= size) {
    throw invalid_argument("Invalid index");
  }
  return mem[val];
}

const void AllocatorFloat::printAllocator() {
  for (int i = 0; i < this->getSize(); i++) {
    cout << *(*this)[i] << endl;
  }
}

template <typename T> T **create_2d_array(int rows, int cols) {
  T **arr = new T *[rows];
  for (int i = 0; i < rows; i++) {
    arr[i] = new T[cols];
  }
  return arr;
}

// delete 2d array
template <typename T> void delete_2d_array(T **arr, int rows) {
  for (int i = 0; i < rows; i++) {
    delete arr[i];
    arr[i] = nullptr;
  }
  delete[] arr;
  arr = nullptr;
}

// resize 2d array
template <typename T>
T **resize_2d_array(T **arr, int rows, int cols, int new_rows, int new_cols) {
  T **new_arr = create_2d_array<T>(new_rows, new_cols);
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      new_arr[i][j] = arr[i][j];
    }
  }
  delete_2d_array(arr, rows);
  return new_arr;
}

float *AllocatorFloat::giveFloat(float val) {
  // allocate memory for an element of float on the heap assigned to be
  // logically equal to val
  float *ptr = new float(val);

  // add pointer to mem array
  if (mem == nullptr) {
    // size : num of elements that have been allocated
    // capacity : Num of elements it can hold
    // size will be 0
    // capacity will be 0
    mem = resize_2d_array(mem, size, capacity, capacity + 5, size + 5);
    mem[size] = ptr;
    size += 1;
    capacity += 5;
    // size will be 1 (1 element added)
    // capacity will be 5 (4 more can be added)
  } else if (capacity == size) {
    mem = resize_2d_array(mem, size, capacity, capacity * 2, capacity * 2);
    capacity *= 2;
    mem[size] = ptr;
    size += 1;
  } else {
    mem[size] = ptr;
    size += 1;
  }
  return ptr;
}

// RULE OF THREE
/*
 public:
//Destructor
~MyClass(){};
//Copy Constructor
MyClass(const MyClass& obj){};
//Copy Assignment
MyClass& operator=(const MyClass& rhg);
 */

/*********
 * Question 2
 */

AllocatorFloat::~AllocatorFloat() {
  for (int i = 0; i < size; i++) {
    delete mem[i];
    mem[i] = nullptr;
  }
  delete[] mem;
  mem = nullptr;
  size = 0;
  capacity = 0;
}

AllocatorFloat::AllocatorFloat(const AllocatorFloat &other)
    : mem(other.mem), size(other.size), capacity(other.capacity) {}

AllocatorFloat &AllocatorFloat::operator=(const AllocatorFloat &other) {
  capacity = other.capacity;
  size = other.size;
  mem = other.mem;
  return *this;
}

/*******************************************
 * Question 3
 */

class Node {
public:
  string value;
  Node *next;
  Node(string value, Node *node = nullptr) : value(value), next(node) {}
};

class LinkedList {
private:
  Node *head;

public:
  LinkedList() : head(nullptr) {}

  void push_front(string value) {
    Node *new_node = new Node(value, head);
    head = new_node;
  }

  string to_string() const {
    std::string output;
    Node *node = head;
    while (node != nullptr) {
      output += node->value + " ";
      node = node->next;
    }

    return output;
  }

  void filterColor(string f);
};

void LinkedList::filterColor(string f) {
  // finds and removed all nodes matching f
  Node *prev = nullptr;
  Node *node = head;
  while (node != nullptr) {
    if (node->value == f) {
      if (prev == nullptr) {
        if (node->next == nullptr) {
          head = nullptr;
        } else {
          head = node->next;
        }
      } else {
        if (node->next == nullptr) {
          prev->next = nullptr;
        } else {
          prev->next = node->next;
        }
      }
    }
    prev = node;
    node = node->next;
  }
}

int main() {
  // i hope i do well :3
  AllocatorFloat a;
  float *val1 = a.giveFloat(0.5);
  cout << "*val1: " << *val1 << endl;

  /*
  LinkedList list;
  list.push_front("yellow");
  list.push_front("green");
  list.push_front("blue");
  list.push_front("green");
  list.push_front("red");
  cout << list.to_string() << endl;
  list.filterColor("green");
  cout << list.to_string() << endl;
  list.filterColor("purple");
  cout << list.to_string() << endl;
  list.filterColor("yellow");
  cout << list.to_string() << endl;
  list.filterColor("red");
  cout << list.to_string() << endl;
  list.filterColor("blue");
  cout << "nu" << list.to_string() << "ll" << endl;
*/
  return 0;
}
