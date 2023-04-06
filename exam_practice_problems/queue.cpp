#include <iostream>
using namespace std;

struct Queue {
  int *data;
  int count;
  int size;

  Queue() {
    data = new int[10];
    count = 0;
    size = 10;
  }

  void enqueue(int v) {
    if (count == size) {
      int *newData = new int[size * 2];
      for (int i = 0; i < size; i++) {
        newData[i] = data[i];
      }
      delete[] data;
      data = newData;
      size *= 2;
    }
    data[count] = v;
    count++;
  }

  int dequeue() {
    if (count == 0) {
      return -1;
    }
    int v = data[0];
    for (int i = 0; i < count - 1; i++) {
      data[i] = data[i + 1];
    }
    count--;
    return v;
  }

  int front() {
    if (count == 0) {
      return -1;
    }
    return data[0];
  }

  int back() {
    if (count == 0) {
      return -1;
    }
    return data[count - 1];
  }

  int length() { return count; }

  bool empty() { return count == 0; }

  void print() {
    for (int i = 0; i < count; i++) {
      cout << data[i] << " ";
    }
    cout << endl;
  }
};

int main() {
  Queue queue = Queue();

  for (int i = 0; i < 25; i++) {
    queue.enqueue(i * 10);
  }

  queue.print();

  for (int i = 0; i < 5; i++) {
    cout << queue.dequeue() << " ";
  }
  cout << endl;

  queue.print();
}
