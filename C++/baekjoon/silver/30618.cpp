#include <iostream>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n;
  cin >> n;
  for (int i = 1; i <= n; i += 2) cout << i << " ";
  for (int i = n % 2 == 0 ? n : n - 1; i > 0; i -= 2) cout << i << " ";
  return 0;
}