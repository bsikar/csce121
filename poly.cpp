#include <iostream>
using namespace std;

// Base class
class Shape {
public:
  virtual void draw() { cout << "Drawing a shape..." << endl; }
};

// Derived class 1
class Circle : public Shape {
public:
  void draw() { cout << "Drawing a circle..." << endl; }
};

// Derived class 2
class Square : public Shape {
public:
  void draw() { cout << "Drawing a square..." << endl; }
};

// Main function
int main() {
  // Create an array of pointers to Shape objects
  Shape *shapes[2];

  // Create objects of the derived classes and assign them to the array
  Circle myCircle;
  Square mySquare;
  shapes[0] = &myCircle;
  shapes[1] = &mySquare;

  // Call the draw() method of each object through the Shape pointer
  for (int i = 0; i < 2; i++) {
    shapes[i]->draw();
  }

  return 0;
}
