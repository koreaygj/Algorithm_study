#include <algorithm>
#include <iostream>
#include <vector>
#define fastio cin.tie(0)->ios::sync_with_stdio(0);
using namespace std;

int main(void) {
  fastio;
  int n, m;
  cin >> n >> m;
  int paper, wrong;
  cin >> paper >> wrong;
  int top_range = 0;
  vector<bool> width_range(m + 1, false);
  for (int i = 0; i < wrong; i++) {
    int a, b;
    cin >> a >> b;
    if (top_range < a) top_range = a;
    width_range[b] = true;
  }
  int left = 0, right = n;
  int mid = 0;
  int ans = 1000000;
  while (left <= right) {
    mid = (left + right) / 2;
    if (top_range > mid) {
      left = mid + 1;
      continue;
    }
    int cnt = 0;
    for (int i = 1; i <= m; i++) {
      if (width_range[i]) {
        cnt++;
        i += mid - 1;
      }
    }
    if (cnt <= paper) {
      ans = min(ans, mid);
      right = mid - 1;
    } else {
      left = mid + 1;
    }
  }
  cout << ans << "\n";
  return 0;
}
