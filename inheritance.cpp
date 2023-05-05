#include <iostream>
using namespace std;

// Base class
class Animal {
public:
  virtual void eat() { cout << "Animal is eating..." << endl; }

  virtual void move() { cout << "Animal is moving..." << endl; }

  virtual ~Animal() { cout << "Animal destructor called." << endl; }
};

// Derived class
class Cat : public Animal {
public:
  void meow() { cout << "Cat is meowing..." << endl; }

  virtual void move() { cout << "Cat is walking..." << endl; }

  virtual ~Cat() { cout << "Cat destructor called." << endl; }
};

// Main function
int main() {
  // Create an object of the derived class
  Animal *myCat = new Cat();

  // Call methods of the derived class
  myCat->eat();
  myCat->move();
  delete myCat;

  return 0;
}
