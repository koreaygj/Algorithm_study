#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
#define fastio cin.tie(0)->ios::sync_with_stdio(0)

using namespace std;

int main() {
  fastio;
  int n, k;
  cin >> n >> k;
  string s;
  cin >> s;

  bool eat[s.size()];
  fill(&eat[0], &eat[0] + s.size(), 0);

  int cnt = 0;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == 'P') {
      bool can_eat = false;
      for (int j = i - k > 0 ? i - k : 0; j < i; j++) {
        if (s[j] == 'H' && !eat[j]) {
          eat[j] = 1;
          can_eat = true;
          break;
        };
      }
      if (!can_eat) {
        for (int j = i + 1; j <= min(i + k, (int)s.size() - 1); j++) {
          if (s[j] == 'H' && !eat[j]) {
            eat[j] = 1;
            can_eat = true;
            break;
          };
        }
      }
      if (can_eat) cnt++;
    }
  }
  cout << cnt << "\n";
  return 0;
}