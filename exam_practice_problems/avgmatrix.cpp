#include <iostream>
using namespace std;

void avg_matix(double **in_array, int rows, int columns, double **out_array) {
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      int cnt = 0;
      double result = 0;

      if (i - 1 >= 0) {
        result += in_array[i - 1][j];
        cnt += 1;

        if (j - 1 >= 0) {
          result += in_array[i - 1][j - 1];
          cnt += 1;
        }

        if (j + 1 < columns) {
          result += in_array[i - 1][j + 1];
          cnt += 1;
        }
      }

      if (i + 1 < rows) {
        result += in_array[i + 1][j];
        cnt += 1;

        if (j - 1 >= 0) {
          result += in_array[i + 1][j - 1];
          cnt += 1;
        }

        if (j + 1 < columns) {
          result += in_array[i + 1][j + 1];
          cnt += 1;
        }
      }

      if (j - 1 >= 0) {
        result += in_array[i][j - 1];
        cnt += 1;
      }

      if (j + 1 < columns) {
        result += in_array[i][j + 1];
        cnt += 1;
      }

      out_array[i][j] = result / cnt;
    }
  }
}

int main() {
  double x[3][4] = {{0.5, 2, 1.2, 3}, {-1.0, 1.5, 3.0, 2.4}, {0, 1, 1.5, 2}};

  double **in = new double *[3];
  double **out = new double *[3];
  for (int i = 0; i < 3; i++) {
    in[i] = new double[4];
    out[i] = new double[4];
  }

  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 4; j++) {
      in[i][j] = x[i][j];
    }
  }

  avg_matix(in, 3, 4, out);

  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 4; j++) {
      cout << out[i][j] << " ";
    }
    cout << endl;
  }

  for (int i = 0; i < 3; i++) {
    delete[] in[i];
    in[i] = nullptr;
    delete[] out[i];
    out[i] = nullptr;
  }
  delete[] in;
  delete[] out;
  in = nullptr;
  out = nullptr;

  return 0;
}
