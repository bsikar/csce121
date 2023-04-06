#include <iostream>
#include <vector>
using namespace std;

class License {
public:
  bool ReadStateAndRenewable();
  void Print() const;

private:
  string state;
  char renewable;
};

bool License::ReadStateAndRenewable() {
  string newState;

  cin >> newState;
  if (newState == "finish") {
    return false;
  } else {
    state = newState;
    cin >> renewable;
    return true;
  }
}

void License::Print() const {
  cout << "License: " << state << ", Renewable: " << renewable << endl;
}

class Database {
public:
  void InputLicenses();
  void PrintLicenses();

private:
  vector<License> licenseList;
};

void Database::InputLicenses() {
  License currLicense;
  while (currLicense.ReadStateAndRenewable()) {
    licenseList.push_back(currLicense);
  }
}

void Database::PrintLicenses() {
  unsigned int i;
  License currLicense;

  for (i = 0; i < licenseList.size(); ++i) {
    currLicense = licenseList.at(i);
    currLicense.Print();
  }
}

int main() {
  Database database;

  database.InputLicenses();
  database.PrintLicenses();

  return 0;
}
