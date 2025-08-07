#include <algorithm>
#include <iostream>
#include <vector>

#define fastio cin.tie(0)->ios::sync_with_stdio(0)

using namespace std;

int main() {
  fastio;
  int n, l;
  cin >> n >> l;
  int drink_sum[n];
  for (int i = 0; i < n; i++) {
    cin >> drink_sum[i];
    if (i > 0) drink_sum[i] += drink_sum[i - 1];
  }

  int cnt = 0;
  for (int i = 0; i < n; i++) {
    int tmp = i < l ? drink_sum[i] : drink_sum[i] - drink_sum[i - l];
    if (129 <= tmp && tmp <= 138) cnt++;
    }
  cout << cnt << "\n";
  return 0;
}