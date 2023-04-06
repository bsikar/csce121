#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

class Eatery {
public:
  void SetName(string eateryName);
  void SetRating(int eateryRating);
  void Print() const;

private:
  string name;
  int rating;
};

void Eatery::SetName(string eateryName) {
  this->name = eateryName + "'s Diner";
}
void Eatery::SetRating(int eateryRating) { this->rating = eateryRating; }

void Eatery::Print() const {
  cout << "Eatery: " << name << endl;
  cout << "Rating: " << rating << " stars" << endl;
}

int main() {
  Eatery restaurant;
  string inputName;
  int inputRating;

  cin >> inputName;
  cin >> inputRating;
  restaurant.SetName(inputName);
  restaurant.SetRating(inputRating);

  restaurant.Print();

  return 0;
}
