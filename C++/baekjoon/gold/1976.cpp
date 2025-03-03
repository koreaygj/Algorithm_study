#include <algorithm>
#include <iostream>
using namespace std;
int Parent[201];
int Find(int x) {
  if (x == Parent[x])
    return x;
  else {
    int y = Find(Parent[x]);
    Parent[x] = y;
    return y;
  }
}
void Union(int x, int y) {
  x = Find(x);
  y = Find(y);
  if (x == y)
    return;
  else {
    if (x > y)
      Parent[x] = y;
    else
      Parent[y] = x;
  }
}
int main(void) {
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    Parent[i] = i;
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      int a;
      cin >> a;
      if (a == 1) {
        Union(i, j);
      }
    }
  }
  bool possible = true;
  int first;
  cin >> first;
  int root = Find(first);

  for (int i = 1; i < m; i++) {
    int a;
    cin >> a;
    if (root != Find(a)) {
      possible = false;
      break;
    }
  }

  if (possible) {
    cout << "YES\n";
  } else {
    cout << "NO\n";
  }
}