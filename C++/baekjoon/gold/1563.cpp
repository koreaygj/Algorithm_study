#include <algorithm>
#include <iostream>
#include <vector>

#define fastio cin.tie(0)->ios::sync_with_stdio(false)

int MOD = 1000000;

using namespace std;

int main() {
  fastio;
  int n;
  cin >> n;
  int dp[n][2][3];
  fill(&dp[0][0][0], &dp[0][0][0] + n * 2 * 3, 0);
  dp[0][0][0] = 1;
  dp[0][1][0] = 1;
  dp[0][0][1] = 1;
  for (int i = 1; i < n; i++) {
    // 출석
    dp[i][0][0] += (dp[i - 1][0][0] + dp[i - 1][0][1] + dp[i - 1][0][2]) % MOD;
    dp[i][1][0] += (dp[i - 1][1][0] + dp[i - 1][1][1] + dp[i - 1][1][2]) % MOD;
    // 지각
    dp[i][1][0] += (dp[i - 1][0][0] + dp[i - 1][0][1] + dp[i - 1][0][2]) % MOD;
    // 결석
    dp[i][0][1] += dp[i - 1][0][0] % MOD;
    dp[i][0][2] += dp[i - 1][0][1] % MOD;
    dp[i][1][1] += dp[i - 1][1][0] % MOD;
    dp[i][1][2] += dp[i - 1][1][1] % MOD;
  }

  cout << (dp[n - 1][0][0] + dp[n - 1][0][1] + dp[n - 1][0][2] +
           dp[n - 1][1][0] + dp[n - 1][1][1] + dp[n - 1][1][2]) %
              MOD
       << "\n";
}