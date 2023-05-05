#include <iostream>
using namespace std;

class Animal {
public:
  virtual void speak() const;
  virtual void eat();
  virtual void move();
  void setAge();
  int getAge() const;
  bool alive;

protected:
  string utterance;

private:
  int age;
};

void Animal::speak() const {}
void Animal::eat() {}
void Animal::move() {}
void Animal::setAge() { age = 3; }
int Animal::getAge() const { return age; }

class Animal2 : public Animal {
public:
  void foo();
  void print();
};

void Animal2::print() { cout << alive << " " << utterance << " " << endl; }

void Animal2::foo() {
  alive = true;
  utterance = "test";
}

void Animal2::speak() const {}
void Animal2::eat() {}
void Animal2::move() {}
void Animal2::setAge() {}
int Animal2::getAge() const {}

int main() {
  Animal2 a = Animal2();
  a.foo();
  a.alive = false;
  a.print();

  return 0;
}
