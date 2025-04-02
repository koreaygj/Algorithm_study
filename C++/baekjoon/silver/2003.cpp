#include <algorithm>
#include <iostream>
#define fastio cin.tie(0)->ios::sync_with_stdio(0)
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  int sum[n + 1];
  sum[0] = 0;
  for (int i = 1; i <= n; i++) {
    int tmp;
    cin >> tmp;
    sum[i] = sum[i - 1] + tmp;
  }
  int st = 1;
  int end = 1;
  int ans = 0;
  while (st <= n && end <= n) {
    int range_sum = sum[end] - sum[st - 1];
    if (range_sum >= m) {
      st++;
      if (range_sum == m) ans++;
    } else {
      end++;
    }
  }
  cout << ans << "\n";
}