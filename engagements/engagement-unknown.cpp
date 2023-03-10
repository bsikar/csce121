#include <iostream>

using std::cin;
using std::cout;
using std::endl;

void allocate_memory(int **&matrix, int num_rows, int num_cols);
void initalize_matrix(int **&matrix, int num_rows, int num_cols);
void print_matrix(int **&matrix, int num_rows, int num_cols);

int main() {
  int rows;
  int cols;

  // ask for the numbers of rows and columns
  cout << "How many Rows for the first matrix? : ";
  cin >> rows;

  cout << "How many Columns for the first matrix? : ";
  cin >> cols;

  int **matrix1;
  allocate_memory(matrix1, rows, cols);
  initalize_matrix(matrix1, rows, cols);

  // ask for the numbers of rows and columns
  cout << "How many Rows for the second matrix? : ";
  cin >> rows;

  cout << "How many Columns for the second matrix? : ";
  cin >> cols;

  int **matrix2;
  allocate_memory(matrix2, rows, cols);
  initalize_matrix(matrix2, rows, cols);

  // make a third matrix
  //
  // add to the third
  //
  // print the third

  return 0;
}

void allocate_memory(int **&matrix, int num_rows, int num_cols) {
  matrix = new int *[num_rows];

  for (int i = 0; i < num_rows; i++) {
    matrix[i] = new int[num_cols];
  }
}

void initalize_matrix(int **&matrix, int num_rows, int num_cols) {
  for (int i = 0; i < num_rows; i++) {
    for (int j = 0; j < num_cols; j++) {
      matrix[i][j] = i + j;
    }
  }
}

void print_matrix(int **&matrix, int num_rows, int num_cols) {
  cout << "[" << endl;
  for (int i = 0; i < num_rows; i++) {
    cout << "\t[";
    for (int j = 0; j < num_cols - 1; j++) {
      cout << matrix[i][j] << ", ";
    }
    cout << matrix[i][num_cols - 1] << "]" << endl;
  }

  cout << "]" << endl;
}
