#include <algorithm>
#include <iostream>
#define MIN -987654321
#define fastio cin.tie(0)->ios::sync_with_stdio(0)
using namespace std;
int main() {
  fastio;
  int n, m;
  int mars[1005][1005];
  int dp[1005][1005];
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> mars[i][j];
    }
  }
  fill(&dp[0][0], &dp[0][0] + 1005 * 1005, MIN);
  dp[1][0] = 0;
  dp[0][1] = 0;

  for (int j = 1; j <= m; j++) {
    dp[1][j] = dp[1][j - 1] + mars[1][j];
  }

  for (int i = 2; i <= n; i++) {
    int left_to_right[1005];
    left_to_right[0] = MIN;
    for (int j = 1; j <= m; j++) {
      left_to_right[j] = max(left_to_right[j - 1], dp[i - 1][j]) + mars[i][j];
    }
    int right_to_left[1005];
    right_to_left[m + 1] = MIN;
    for (int j = m; j >= 1; j--) {
      right_to_left[j] = max(right_to_left[j + 1], dp[i - 1][j]) + mars[i][j];
    }
    for (int j = 1; j <= m; j++) {
      dp[i][j] = max(left_to_right[j], right_to_left[j]);
    }
  }
  cout << dp[n][m] << "\n";
}
