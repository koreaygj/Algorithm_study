#include <cstring>
#include <iostream>
using namespace std;
int main() {
  int n;
  cin >> n;
  int ans = 0;
  int paper[100][100];
  for (int i = 0; i < 100; i++) {
    for (int j = 0; j < 100; j++) paper[i][j] = 0;
  }
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    int a, b;
    cin >> a >> b;
    for (int j = b - 1; j < b + 9; j++) {
      for (int k = a - 1; k < a + 9; k++) {
        if (paper[j][k]) continue;
        paper[j][k] = 1;
        cnt++;
      }
    }
  }
  cout << cnt << "\n";
}