#include <iomanip>
#include <iostream>
using namespace std;

int main() {
  int chemistryGrade;
  int koreanGrade;
  int germanGrade;
  int numGrades;

  cin >> chemistryGrade;
  cin >> koreanGrade;
  cin >> germanGrade;
  cin >> numGrades;

  float averageGrade = (chemistryGrade + koreanGrade + germanGrade) /
                       static_cast<float>(numGrades);

  cout << fixed << setprecision(2) << averageGrade << endl;

  return 0;
}
