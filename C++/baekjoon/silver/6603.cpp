#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
vector<int> Set;
void dfs(int k, int st, int cnt, string ans) {
  if (cnt == 6) {
    cout << ans << "\n";
    return;
  }
  for (int i = st + 1; i < k; i++) {
    dfs(k, i, cnt + 1, ans + to_string(Set[i]) + " ");
  }
  return;
}
int main() {
  int k;
  bool first = true;
  while (cin >> k) {
    if (k == 0) break;
    if (!first) {
      cout << "\n";
    }
    first = false;
    Set = vector<int>(k, 0);
    for (int i = 0; i < k; i++) cin >> Set[i];
    for (int i = 0; i < k; i++) {
      dfs(k, i, 1, to_string(Set[i]) + " ");
    }
  }
}