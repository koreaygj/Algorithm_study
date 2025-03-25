#include <iostream>
#define INF 987654321;
using namespace std;
int main() {
  int n;
  cin >> n;
  int cost[n + 1][3];
  for (int i = 0; i <= n + 1; i++)
    for (int j = 0; j < 3; j++) cost[i][j] = 0;
  for (int i = 0; i < n; i++) {
    cin >> cost[i][0] >> cost[i][1] >> cost[i][2];
  }
  int dp[1001][3];
  for (int i = 0; i < 1001; i++) {
    for (int j = 0; j < 3; j++) dp[i][j] = 0;
  }
  int ans = INF;
  for (int i = 0; i < 3; i++) {
    dp[0][0] = i == 0 ? cost[0][0] : INF;
    dp[0][1] = i == 1 ? cost[0][1] : INF;
    dp[0][2] = i == 2 ? cost[0][2] : INF;
    for (int j = 1; j < n; j++) {
      dp[j][0] = cost[j][0];
      dp[j][0] += dp[j - 1][1] < dp[j - 1][2] ? dp[j - 1][1] : dp[j - 1][2];
      dp[j][1] = cost[j][1];
      dp[j][1] += dp[j - 1][0] < dp[j - 1][2] ? dp[j - 1][0] : dp[j - 1][2];
      dp[j][2] = cost[j][2];
      dp[j][2] += dp[j - 1][0] < dp[j - 1][1] ? dp[j - 1][0] : dp[j - 1][1];
    }
    int tmp = 0;
    if (i == 0) {
      tmp = dp[n - 1][1] < dp[n - 1][2] ? dp[n - 1][1] : dp[n - 1][2];
    } else if (i == 1) {
      tmp = dp[n - 1][0] < dp[n - 1][2] ? dp[n - 1][0] : dp[n - 1][2];
    } else {
      tmp = dp[n - 1][0] < dp[n - 1][1] ? dp[n - 1][0] : dp[n - 1][1];
    }
    ans = tmp < ans ? tmp : ans;
  }
  cout << ans << "\n";
}