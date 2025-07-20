#include <algorithm>
#include <cmath>
#include <iostream>
#include <queue>
#include <vector>
#define fastio cin.tie(0)->ios::sync_with_stdio(0)

using namespace std;

struct State {
  int x, y, cnt, idx;

  State(int x, int y, int cnt, int idx) : x(x), y(y), cnt(cnt), idx(idx) {}
};

bool cmp(pair<int, int> a, pair<int, int> b) {
  if (a.second == b.second)
    return a.first < b.first;
  else
    return a.second < b.second;
}

int main() {
  fastio;
  int n, t;
  cin >> n >> t;

  vector<pair<int, int>> arr(n);
  vector<bool> visit(n, false);

  for (int i = 0; i < n; i++) {
    cin >> arr[i].first >> arr[i].second;
  }

  sort(arr.begin(), arr.end(), cmp);

  queue<State> q;
  q.push(State(0, 0, 0, 0));

  while (!q.empty()) {
    State cur = q.front();
    q.pop();

    if (cur.y == t) {
      cout << cur.cnt << "\n";
      return 0;
    }

    for (int i = cur.idx; i < n; i++) {
      int nx = arr[i].first;
      int ny = arr[i].second;

      if (!visit[i]) {
        if (abs(cur.x - nx) <= 2 && abs(cur.y - ny) <= 2) {
          visit[i] = true;
          q.push(State(nx, ny, cur.cnt + 1, i));
        } else if (ny > cur.y + 2)
          break;
      }
    }

    for (int i = cur.idx - 1; i >= 0; i--) {
      int nx = arr[i].first;
      int ny = arr[i].second;

      if (!visit[i]) {
        if (abs(cur.x - nx) <= 2 && abs(cur.y - ny) <= 2) {
          visit[i] = true;
          q.push(State(nx, ny, cur.cnt + 1, i));
        } else if (ny < cur.y - 2)
          break;
      }
    }
  }

  cout << -1 << "\n";
  return 0;
}