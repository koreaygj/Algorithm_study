#include <algorithm>
#include <iostream>
#define fastio cin.tie(0)->ios::sync_with_stdio(0)
using namespace std;
int main() {
  fastio;
  int n, k;
  cin >> n >> k;
  int cost[n];
  for (int i = 0; i < n; i++) cin >> cost[i];
  int st = 0;
  int end = k - 1;
  int ans = 0;
  bool is_selected[n];
  fill(&is_selected[0], &is_selected[0] + n, false);
  while (end < n) {
    bool can_skip = false;
    int min_index = -1;
    int min_cost = 1000000000;
    for (int i = st; i <= end; i++) {
      if (is_selected[i]) {
        can_skip = true;
        break;
      }
      if (min_cost > cost[i]) {
        min_cost = cost[i];
        min_index = i;
      }
    }
    if (!can_skip) {
      is_selected[min_index] = true;
      ans = min_cost > ans ? min_cost : ans;
    }
    st++;
    end++;
  }
  cout << ans << "\n";
}