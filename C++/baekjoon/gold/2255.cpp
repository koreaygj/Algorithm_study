#include <iostream>
#define MOD 1000000000
using namespace std;
int main() {
  int n, k;
  cin >> n >> k;
  if (k == 1) {
    cout << 1 << "\n";
    return 0;
  }
  long long dp[201][201];
  for (int i = 0; i <= k; i++) {
    for (int j = 0; j <= n; j++) {
      if (i == 1)
        dp[i][j] = 1;
      else if (i == 2)
        dp[i][j] = j + 1;
      else
        dp[i][j] = 0;
    }
  }
  for (int i = 3; i <= k; i++) {
    for (int j = 3; j <= i; j++) {
      long long value = 0;
      for (int l = 0; l <= n; l++) {
        value += dp[j - 1][l] % MOD;
        dp[j][l] = value % MOD;
      }
    }
  }
  cout << dp[k][n] << "\n";
}