#include <algorithm>
#include <iostream>
#define MOD 10007
using namespace std;
int main() {
  int n;
  cin >> n;
  int dp[11][n + 1];
  fill(&dp[0][0], &dp[0][0] + 11 * (n + 1), 0);
  for (int i = 0; i < 10; i++) dp[i][0] = 1;
  for (int j = 1; j < n; j++) {
    for (int i = 0; i < 10; i++) {
      if (i == 0)
        dp[i][j] = dp[i][j - 1];
      else
        dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % MOD;
    }
  }
  int ans = 0;
  for (int i = 0; i < 10; i++) ans += dp[i][n - 1] % MOD;
  cout << ans % MOD << "\n";
}