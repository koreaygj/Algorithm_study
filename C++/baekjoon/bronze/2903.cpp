#include <algorithm>
#include <iostream>
#define fastio cin.tie(0)->ios::sync_with_stdio(0);
using namespace std;
int sol(int n) {
  if (n == 1) return 3;
  return sol(n - 1) * 2 - 1;
}
int main() {
  int n;
  cin >> n;
  int size = sol(n);
  cout << size * size << "\n";
}