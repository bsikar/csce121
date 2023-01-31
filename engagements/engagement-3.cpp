#include <iostream>
#include <vector>

int sum(std::vector<int> v) {
  int sum = 0;
  for (int i = 0; i < v.size(); i++) {
    sum += v[i];
  }
  return sum;
}

int average(std::vector<int> v) {
  int sum = 0;
  for (int i = 0; i < v.size(); i++) {
    sum += v[i];
  }
  return sum / v.size();
}

int main() {
  std::vector<int> v;
  int n;
  std::cout << "Enter a sequence of numbers (^D to stop): ";
  while (std::cin >> n) {
    v.push_back(n);
  }
  std::cout << "Sum: " << sum(v) << std::endl;
  std::cout << "Average: " << average(v) << std::endl;
  return 0;
}
