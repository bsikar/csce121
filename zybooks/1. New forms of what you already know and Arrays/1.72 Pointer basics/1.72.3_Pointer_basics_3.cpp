#include <iostream>
using namespace std;

void ReadLabel(char *labelPointer) {
  if (labelPointer == nullptr) {
    cout << "labelPointer is null." << endl;
  } else {
    cin >> *labelPointer;
  }
}

int main() {
  char label;
  char *labelPointer;
  char action;

  label = '0';
  cin >> action;

  if (action == 'Y') {
    labelPointer = &label;
  } else {
    labelPointer = nullptr;
  }

  ReadLabel(labelPointer);
  cout << "Label is " << label << "." << endl;

  return 0;
}
