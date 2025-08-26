#include <algorithm>
#include <iostream>
#include <vector>
#define fastio cin.tie(0)->ios::sync_with_stdio(0)

using namespace std;

int main() {
  fastio;
  int n, m;
  cin >> n >> m;

  vector<pair<int, int>> hands;

  for (int i = 1; i <= m; i++) {
    int h1, h2;
    cin >> h1 >> h2;
    hands.push_back({h1, i});
    hands.push_back({h2, i});
  }

  sort(hands.begin(), hands.end());

  int ans = (n - 1) % (2 * m);
  cout << hands[ans].second << "\n";

  return 0;
}