#include <algorithm>
#include <iostream>

#define fastio cin.tie(0)->ios::sync_with_stdio(false)

using namespace std;

const int MOD = 1000000007;

int main() {
  fastio;
  int n;
  cin >> n;
  long long int dp[2][n + 1];
  dp[0][0] = 1;
  dp[0][1] = 2;
  dp[0][2] = 7;
  dp[1][2] = 0;
  for (int i = 3; i <= n; i++) {
    dp[1][i] = (dp[0][i - 3] + dp[1][i - 1]) % MOD;
    dp[0][i] = (dp[0][i - 1] * 2 + dp[0][i - 2] * 3 + dp[1][i] * 2) % MOD;
  }

  cout << dp[0][n] % MOD << "\n";
  return 0;
}