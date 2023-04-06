#include <iostream>
using namespace std;

void minus_odd_column(int **mat, int n) {
  int odds = 0;
  int indx = -1;

  for (int i = 0; i < n; i++) {
    int in_odds = 0;
    for (int j = 0; j < n; j++) {
      if (mat[j][i] % 2 == 1) {
        in_odds += 1;
      }

      if (in_odds > odds) {
        indx = i;
        odds = in_odds;
      }
    }
  }

  for (int i = 0; i < n; i++) {
    mat[i][indx] = -1;
  }
}

int main() {
  const int n = 5;
  int x[n][n] = {{0, 30, 10, 70, 10},
                 {30, 0, 45, 100, 50},
                 {10, 45, 0, 85, 20},
                 {70, 100, 85, 0, 100},
                 {10, 50, 20, 100, 0}};
  int **mat = new int *[n];
  for (int i = 0; i < n; i++) {
    mat[i] = new int[n];
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      mat[i][j] = x[i][j];
    }
  }

  minus_odd_column(mat, n);

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cout << mat[i][j] << " ";
    }
    cout << endl;
  }

  for (int i = 0; i < n; i++) {
    delete[] mat[i];
    mat[i] = nullptr;
  }
  delete[] mat;
  mat = nullptr;
  return 0;
}
