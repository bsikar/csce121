#include <iostream>
using namespace std;

class Business {
public:
  int GetNumEmployees() const;
  int GetYearsOpen() const;
  int GetNumStock() const;
  /* Member function declarations go here */

  void SetNumEmployees(int);
  void SetYearsOpen(int);
  void SetNumStock(int);

private:
  /* Data members go here */
  int numEmployees;
  int yearsOpen;
  int numStock;
};

void Business::SetNumEmployees(int customNumEmployees) {
  numEmployees = customNumEmployees;
}

void Business::SetYearsOpen(int customYearsOpen) {
  yearsOpen = customYearsOpen;
}

void Business::SetNumStock(int customNumStock) { numStock = customNumStock; }

int Business::GetNumEmployees() const { return numEmployees; }

int Business::GetYearsOpen() const { return yearsOpen; }

int Business::GetNumStock() const { return numStock; }

int main() {
  Business business1;
  int inputNumEmployees;
  int inputYearsOpen;
  int inputNumStock;

  cin >> inputNumEmployees;
  cin >> inputYearsOpen;
  cin >> inputNumStock;

  business1.SetNumEmployees(inputNumEmployees);
  business1.SetYearsOpen(inputYearsOpen);
  business1.SetNumStock(inputNumStock);
  cout << "Number of employees: " << business1.GetNumEmployees() << endl;
  cout << "Years open: " << business1.GetYearsOpen() << endl;
  cout << "Items in stock: " << business1.GetNumStock() << endl;

  return 0;
}
