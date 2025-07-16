#include <algorithm>
#include <iostream>
#include <vector>
#define fastio cin.tie(0)->ios::sync_with_stdio(0);

using namespace std;

int main() {
  fastio;
  int n;
  while (cin >> n && n != 0) {
    int chargers[n];
    for (int i = 0; i < n; i++) cin >> chargers[i];
    sort(&chargers[0], &chargers[n]);

    bool is_possible = true;
    if (chargers[0] != 0 || 1422 - chargers[n - 1] > 100) is_possible = false;
    for (int i = 0; i < n - 1; i++) {
      if (chargers[i + 1] - chargers[i] > 200) {
        is_possible = false;
        break;
      }
    }

    if (is_possible)
      cout << "POSSIBLE\n";
    else
      cout << "IMPOSSIBLE\n";
  }
  return 0;
}