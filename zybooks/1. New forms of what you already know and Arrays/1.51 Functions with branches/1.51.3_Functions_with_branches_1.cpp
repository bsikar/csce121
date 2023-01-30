#include <iostream>
using namespace std;

int FindProjectPriority(int taskCount) {
  int priority;
  if (taskCount < 20) {
    priority = 1;
  } else if (taskCount >= 20 && taskCount <= 60) {
    priority = 2;
  } else {
    priority = 3;
  }
  return priority;
}

int main() {
  int tasksNumber;

  cin >> tasksNumber;

  cout << FindProjectPriority(tasksNumber) << endl;

  return 0;
}
