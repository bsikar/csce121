#include <iostream>
using namespace std;

// create 2d array

template <typename T> T **create_2d_array(int rows, int cols) {
  T **arr = new T *[rows];
  for (int i = 0; i < rows; i++) {
    arr[i] = new T[cols];
  }
  return arr;
}

// delete 2d array
template <typename T> void delete_2d_array(T **arr, int rows) {
  for (int i = 0; i < rows; i++) {
    delete[] arr[i];
    arr[i] = nullptr;
  }
  delete[] arr;
  arr = nullptr;
}

// print 2d array
template <typename T> void print_2d_array(T **arr, int rows, int cols) {
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      cout << arr[i][j] << " ";
    }
    cout << endl;
  }
}

// fill 2d array
template <typename T> void fill_2d_array(T **arr, int rows, int cols) {
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      arr[i][j] = i + j;
    }
  }
}

template <typename T> void fill_2d_array(T **arr, int rows, int cols, T value) {
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      arr[i][j] = value;
    }
  }
}

// resize 2d array
template <typename T>
T **resize_2d_array(T **arr, int rows, int cols, int new_rows, int new_cols) {
  T **new_arr = create_2d_array<T>(new_rows, new_cols);
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      new_arr[i][j] = arr[i][j];
    }
  }
  delete_2d_array(arr, rows);
  return new_arr;
}

void rotateRight(double **&ary, unsigned int &numRows, unsigned int numCols) {
  // check for null
  if (ary == nullptr) {
    throw runtime_error("Tried to rotate a null array");
  }
  // check for numRows and numCols
  if (numRows == 0 || numCols == 0) {
    throw runtime_error(
        "Tried to rotate an array with numRows or numCols equal to 0");
  }

  double **new_ary = create_2d_array<double>(numCols, numRows);
  for (int i = 0; i < numCols; i++) {
    for (int j = 0; j < numRows; j++) {
      new_ary[i][numRows - j - 1] = ary[j][i];
    }
  }

  delete_2d_array(ary, numRows);
  ary = new_ary;
}

int main() {
  double **arr = create_2d_array<double>(3, 5);
  fill_2d_array(arr, 3, 5);

  print_2d_array(arr, 3, 5);

  unsigned int numRows = 3;

  rotateRight(arr, numRows, 5);

  print_2d_array(arr, 5, 3);
  delete_2d_array(arr, 5);
  arr = nullptr;

  return 0;
}
