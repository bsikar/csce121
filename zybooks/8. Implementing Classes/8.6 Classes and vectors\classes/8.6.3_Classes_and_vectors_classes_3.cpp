#include <iostream>
#include <vector>
using namespace std;

class License {
public:
  void SetStateAndFee(string newState, int newFee);
  void Print() const;

private:
  string state;
  int fee;
};

void License::SetStateAndFee(string newState, int newFee) {
  state = newState;
  fee = newFee;
}

void License::Print() const {
  cout << "License: " << state << ", Fee: " << fee << endl;
}

class Database {
public:
  void InputLicenses();
  void PrintLicenses();

private:
  vector<License> licenseList;
};

void Database::InputLicenses() {
  int licenseCount;
  unsigned int i;
  License currLicense;
  string currState;
  int currFee;

  cin >> licenseCount;
  for (i = 0; i < licenseCount; ++i) {
    cin >> currState;
    cin >> currFee;

    currLicense.SetStateAndFee(currState, currFee);
    licenseList.push_back(currLicense);
  }
}

void Database::PrintLicenses() {
  unsigned int i;
  for (i = 0; i < licenseList.size(); ++i) {
    licenseList.at(i).Print();
  }
}

int main() {
  Database database;

  database.InputLicenses();
  database.PrintLicenses();

  return 0;
}
