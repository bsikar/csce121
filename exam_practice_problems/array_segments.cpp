int array_segments(int *arr, int size_of_arr) {
  int count = 1;
  for (int i = 1; i < size_of_arr; i++) {
    if (arr[i] != arr[i - 1]) {
      count++;
    }
  }
  return count;
}
