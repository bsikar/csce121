#include <iostream>
using namespace std;

class DriverLicense {
public:
  void SetId(int newId);
  void SetYear(int newYear);
  int GetId() const;
  int GetYear() const;

private:
  int id;
  int year;
};

void DriverLicense::SetId(int newId) { id = newId; }

void DriverLicense::SetYear(int newYear) { year = newYear; }

int DriverLicense::GetId() const { return id; }

int DriverLicense::GetYear() const { return year; }

int main() {
  DriverLicense driver1;
  int userId;
  int userYear;

  cin >> userId;
  cin >> userYear;

  driver1.SetId(userId);
  driver1.SetYear(userYear);
  cout << "License id: " << driver1.GetId() << endl;
  cout << "License year: " << driver1.GetYear() << endl;

  return 0;
}
