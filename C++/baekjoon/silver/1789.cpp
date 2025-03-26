#include <iostream>
using namespace std;
int main() {
  long long int n;
  cin >> n;
  long long int ans = 0;
  for (int i = 1; i <= n; i++) {
    if (n - i < 0) break;
    n -= i;
    ans++;
  }
  cout << ans << "\n";
}