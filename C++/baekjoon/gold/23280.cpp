#include <algorithm>
#include <climits>
#include <iostream>
#define fastio cin.tie(0)->ios::sync_with_stdio(0)
#define INF LLONG_MAX
using namespace std;

pair<int, int> getCoord(int num) {
  int row = (num - 1) / 3;
  int col = (num - 1) % 3;
  return {row, col};
}

int distance(int pos1, int pos2) {
  auto [r1, c1] = getCoord(pos1);
  auto [r2, c2] = getCoord(pos2);
  return abs(r1 - r2) + abs(c1 - c2);
}

int main() {
  int n, a, b;
  cin >> n >> a >> b;
  int num[n];
  for (int i = 0; i < n; i++) cin >> num[i];
  long long dp[n + 1][13][13];
  fill(&dp[0][0][0], &dp[0][0][0] + (n + 1) * 13 * 13, INF);
  dp[0][1][3] = 0;
  for (int i = 0; i < n; i++) {
    int next_num = num[i];
    for (int left = 1; left <= 12; left++) {
      for (int right = 1; right <= 12; right++) {
        if (dp[i][left][right] == INF) continue;
        long long new_cost = dp[i][left][right] + distance(left, next_num) + a;
        dp[i + 1][next_num][right] = min(dp[i + 1][next_num][right], new_cost);
        new_cost = dp[i][left][right] + distance(right, next_num) + b;
        dp[i + 1][left][next_num] = min(dp[i + 1][left][next_num], new_cost);
      }
    }
  }
  long long result = LLONG_MAX;
  for (int left = 1; left <= 12; left++) {
    for (int right = 1; right <= 12; right++) {
      result = min(result, dp[n][left][right]);
    }
  }
  cout << result << "\n";
}