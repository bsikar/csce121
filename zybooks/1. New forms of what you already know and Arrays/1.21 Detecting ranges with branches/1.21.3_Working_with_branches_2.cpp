#include <iostream>
using namespace std;

int main() {
  int userSalary;
  int companyBudget;

  cin >> userSalary;
  cin >> companyBudget;

  if (userSalary <= 150000) {
    companyBudget -= 150000;
  }

  cout << companyBudget << endl;

  return 0;
}
