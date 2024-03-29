#include <iostream>
using namespace std;

class PersonInfo {
public:
  void SetNumKids(int personsKidsToSet);
  void IncNumKids();
  int GetNumKids() const;

private:
  int numKids;
};

void PersonInfo::SetNumKids(int personsKidsToSet) {
  numKids = personsKidsToSet;
}

void PersonInfo::IncNumKids() { numKids = numKids + 1; }

int PersonInfo::GetNumKids() const { return numKids; }

int main() {
  PersonInfo person1;
  int personsKids;

  cin >> personsKids;

  person1.SetNumKids(personsKids);

  /*
   * Print person1's kids, apply the IncNumKids() function, and print again,
outputting text as below. End each line with a newline. Sample output for below
program with input 3: Kids: 3 New baby, kids now: 4
*/

  cout << "Kids: " << person1.GetNumKids() << endl;
  person1.IncNumKids();
  cout << "New baby, kids now: " << person1.GetNumKids() << endl;

  return 0;
}

// Language: cpp
// Path: 8.2.3_Basic_class_use.cpp
#include <iostream>
using namespace std;

class PersonInfo {
public:
  void SetNumKids(int personsKidsToSet);
  void IncNumKids();
  int GetNumKids() const;

private:
  int numKids;
};

void PersonInfo::SetNumKids(int personsKidsToSet) {
  numKids = personsKidsToSet;
}

void PersonInfo::IncNumKids() { numKids = numKids + 1; }

int PersonInfo::GetNumKids() const { return numKids; }

int main() {
  PersonInfo person1;
  int personsKids;

  cin >> personsKids;

  person1.SetNumKids(personsKids);

  cout << "Kids: " << person1.GetNumKids() << endl;
  person1.IncNumKids();
  cout << "New baby, kids now: " << person1.GetNumKids() << endl;

  return 0;
}
