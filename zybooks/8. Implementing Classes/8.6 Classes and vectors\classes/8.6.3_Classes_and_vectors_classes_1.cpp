#include <iostream>
#include <vector>
using namespace std;

class Student {
public:
  void SetNameAndAge(string newName, int newAge);
  int GetAge() const;
  void Print() const;

private:
  string name;
  int age;
};

void Student::SetNameAndAge(string newName, int newAge) {
  name = newName;
  age = newAge;
}

int Student::GetAge() const { return age; }

void Student::Print() const {
  cout << "Student: " << name << ", Age: " << age << endl;
}

int main() {
  int studentCount;
  unsigned int i;
  vector<Student> studentList;
  Student currStudent;
  string currName;
  int currAge;

  cin >> studentCount;
  for (i = 0; i < studentCount; ++i) {
    cin >> currName;
    cin >> currAge;

    currStudent.SetNameAndAge(currName, currAge);
    studentList.push_back(currStudent);
  }

  for (i = 0; i < studentList.size(); ++i) {
    if (studentList.at(i).GetAge() >= 81 && studentList.at(i).GetAge() <= 84) {
      studentList.at(i).Print();
    }
  }

  return 0;
}
