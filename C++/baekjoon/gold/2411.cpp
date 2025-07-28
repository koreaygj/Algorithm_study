#include <algorithm>
#include <iostream>
#include <vector>
#define fastio cin.tie(0)->ios::sync_with_stdio(0)

using namespace std;

int main() {
  fastio;
  int n, m, a, b;
  cin >> n >> m >> a >> b;

  int map[n][m];
  fill(&map[0][0], &map[0][0] + n * m, 0);
  vector<pair<int, int>> items;
  items.push_back(make_pair(0, 0));
  items.push_back(make_pair(n - 1, m - 1));

  for (int i = 0; i < a; i++) {
    int x, y;
    cin >> x >> y;
    items.push_back(make_pair(x - 1, y - 1));
  }

  sort(items.begin(), items.end());

  for (int i = 0; i < b; i++) {
    int x, y;
    cin >> x >> y;
    map[x - 1][y - 1] = -1;
  }

  map[0][0] = 1;

  for (int i = 0; i < items.size() - 1; i++) {
    pair<int, int> st = items[i];
    pair<int, int> end = items[i + 1];
    for (int j = st.first; j <= end.first; j++) {
      for (int k = st.second; k <= end.second; k++) {
        if (map[j][k] == -1) continue;
        if (j == st.first && k == st.second) continue;

        int top;
        int left;

        if (j - 1 < st.first)
          top = 0;
        else
          top = map[j - 1][k] == -1 ? 0 : map[j - 1][k];

        if (k - 1 < st.second)
          left = 0;
        else
          left = map[j][k - 1] == -1 ? 0 : map[j][k - 1];

        map[j][k] = top + left;
      }
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) cout << map[i][j] << " ";
    cout << endl;
  }

  cout << map[n - 1][m - 1] << "\n";

  return 0;
}