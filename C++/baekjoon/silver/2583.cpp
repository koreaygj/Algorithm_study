#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
#define fastio cin.tie(0)->ios::sync_with_stdio(0);
using namespace std;
int N, M, K;
int Paper[101][101];
int Rect[101][4];
bool Visited[101][101];
bool checkRect(pair<int, int> a) {
  for (int i = 0; i < K; i++) {
    if (Rect[i][1] <= a.first && a.first < Rect[i][3] &&
        Rect[i][0] <= a.second && a.second < Rect[i][2])
      return false;
  }
  return true;
}
int bfs(int y, int x) {
  queue<pair<int, int>> q;
  q.push(make_pair(y, x));
  Visited[y][x] = true;
  int next_y[4] = {-1, 1, 0, 0};
  int next_x[4] = {0, 0, -1, 1};
  int cnt = 1;
  while (!q.empty()) {
    pair<int, int> cur = q.front();
    q.pop();
    for (int i = 0; i < 4; i++) {
      pair<int, int> next =
          make_pair(cur.first + next_y[i], cur.second + next_x[i]);
      if (next.first < 0 || next.first >= N || next.second < 0 ||
          next.second >= M || Visited[next.first][next.second])
        continue;
      if (!checkRect(next)) continue;
      q.push(next);
      Visited[next.first][next.second] = true;
      cnt++;
    }
  }
  return cnt;
}
int main() {
  cin >> N >> M >> K;
  for (int i = 0; i < K; i++) {
    cin >> Rect[i][0] >> Rect[i][1] >> Rect[i][2] >> Rect[i][3];
  }
  vector<int> ans;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      if (!Visited[i][j] && checkRect(make_pair(i, j))) {
        int tmp = bfs(i, j);
        ans.push_back(tmp);
      }
    }
  }
  sort(ans.begin(), ans.end());
  cout << ans.size() << "\n";
  for (const auto val : ans) cout << val << " ";
  cout << "\n";
}