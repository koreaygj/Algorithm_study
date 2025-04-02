#include <algorithm>
#include <iostream>
#define fastio cin.tie(0)->ios::sync_with_stdio(0);
using namespace std;
int main() {
  fastio;
  int e, s, m;
  cin >> e >> s >> m;
  int ans = 0;
  if (e == 15) e = 0;
  if (s == 28) s = 0;
  if (m == 19) m = 0;
  while (true) {
    ans++;
    if (ans % 15 == e && ans % 28 == s && ans % 19 == m) break;
  }
  cout << ans << "\n";
}