#include <iostream>
using namespace std;

double path_length(double **distance, int n, int *path, int m) {
  int prev = path[0];
  double result = 0;
  for (int i = 1; i < m; i++) {
    int curr = path[i];
    result += distance[prev][curr];
    prev = path[i];
  }
  return result;
}

int main() {
  const int n = 5;
  const int m = 3;
  double **distance = new double *[n];
  for (int i = 0; i < n; i++) {
    distance[i] = new double[i];
  }
  double x[n][n] = {{0, 30, 10, 70, 10},
                    {30, 0, 45, 100, 50},
                    {10, 45, 0, 85, 20},
                    {70, 100, 85, 0, 100},
                    {10, 50, 20, 100, 0}};
  int *path = new int[m];
  int y[m] = {0, 1, 2};

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      distance[i][j] = x[i][j];
    }
  }

  for (int i = 0; i < m; i++) {
    path[i] = y[i];
  }

  cout << path_length(distance, n, path, m) << endl;

  for (int i = 0; i < n; i++) {
    delete[] distance[i];
    distance[i] = nullptr;
  }

  delete[] distance;
  delete[] path;
  distance = nullptr;
  path = nullptr;

  return 0;
}
