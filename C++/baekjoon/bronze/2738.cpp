#include <cstring>
#include <iostream>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  int matrix[n][m];
  for (int i = 0; i < n; i++) {
    memset(matrix[i], 0, sizeof(matrix[i]));
  }
  for (int k = 0; k < 2; k++) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        int tmp;
        cin >> tmp;
        matrix[i][j] += tmp;
      }
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) cout << matrix[i][j] << " ";
    cout << "\n";
  }
}