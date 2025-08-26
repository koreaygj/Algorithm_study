#include <algorithm>
#include <iostream>
#include <queue>
#define fastio cin.tie(0)->ios::sync_with_stdio(0)

using namespace std;

bool bfs(int n, pair<int, int> st, pair<int, int> end, pair<int, int> store[],
         bool visited[]) {
  queue<pair<int, int>> q;
  q.push(st);

  while (!q.empty()) {
    pair<int, int> cur = q.front();
    q.pop();
    if (cur == end) {
      cout << "happy\n";
      return true;
    }

    for (int i = 0; i < n + 1; i++) {
      pair<int, int> next = store[i];
      if (!visited[i] &&
          abs(cur.first - next.first) + abs(cur.second - next.second) <= 1000) {
        q.push(next);
        visited[i] = true;
      }
    }
  }

  cout << "sad\n";
  return false;
}

int main() {
  fastio;
  int t;
  cin >> t;
  while (t > 0) {
    t--;

    int n;
    cin >> n;

    bool visited[n + 1];
    fill(&visited[0], &visited[0] + n + 1, 0);
    pair<int, int> st, end;
    pair<int, int> store[n + 1];

    cin >> st.first >> st.second;
    for (int i = 0; i < n; i++) cin >> store[i].first >> store[i].second;
    cin >> end.first >> end.second;
    store[n] = end;

    bfs(n, st, end, store, visited);
  }
  return 0;
}