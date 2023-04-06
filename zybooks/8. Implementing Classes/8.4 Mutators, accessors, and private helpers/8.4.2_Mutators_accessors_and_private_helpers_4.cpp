#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

class Money {
public:
  void SetDollars(int moneyDollars);
  int GetDollars() const;
  void PrintInCents();

private:
  int dollars;
  int ConvertToCents();
};

void Money::SetDollars(int moneyDollars) { dollars = moneyDollars; }

int Money::GetDollars() const { return dollars; }

/* Your code goes here */
int Money::ConvertToCents() { return dollars * 100; }

void Money::PrintInCents() {
  cout << fixed << setprecision(1) << ConvertToCents() << " cents" << endl;
}

int main() {
  Money money1;
  int inputDollars;

  cin >> inputDollars;
  money1.SetDollars(inputDollars);

  money1.PrintInCents();

  return 0;
}
