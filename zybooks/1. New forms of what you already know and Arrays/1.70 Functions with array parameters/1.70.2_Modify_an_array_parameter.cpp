#include <iostream>
using namespace std;

void SwapArrayEnds(int sortArray[], int arraySize) {
  int temp = sortArray[0];
  sortArray[0] = sortArray[arraySize - 1];
  sortArray[arraySize - 1] = temp;
}

int main() {
  const int SORT_ARR_SIZE = 4;
  int sortArray[SORT_ARR_SIZE];
  int i;
  int userNum;

  for (i = 0; i < SORT_ARR_SIZE; ++i) {
    cin >> userNum;
    sortArray[i] = userNum;
  }

  SwapArrayEnds(sortArray, SORT_ARR_SIZE);

  for (i = 0; i < SORT_ARR_SIZE; ++i) {
    cout << sortArray[i] << " ";
  }
  cout << endl;

  return 0;
}
