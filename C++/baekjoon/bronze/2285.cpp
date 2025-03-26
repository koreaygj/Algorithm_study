#include <iostream>
using namespace std;
int main() {
  int n;
  cin >> n;
  n = 1000 - n;
  int coins[] = {500, 100, 50, 10, 5, 1};
  int ans = 0;
  for (int i = 0; i < 6; i++) {
    if (n < 0) break;
    ans += n / coins[i];
    n = n % coins[i];
  }
  cout << ans << "\n";
}