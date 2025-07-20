#include <algorithm>
#include <cmath>
#include <iostream>
#include <queue>
#include <vector>
#define fastio cin.tie(0)->ios::sync_with_stdio(0)

using namespace std;

int main() {
  fastio;
  int n, m;
  cin >> n >> m;

  int x[m];
  for (int i = 0; i < m; i++) cin >> x[i];

  int height = 0;
  height = max(x[0], n - x[m - 1]);
  for (int i = 0; i < m - 1; i++) {
    height = max(height, (int)((x[i + 1] - x[i] + 1) / 2));
  }
  cout << height << "\n";
  return 0;
}