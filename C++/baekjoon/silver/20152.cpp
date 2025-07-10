#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
#define fastio cin.tie(0)->ios::sync_with_stdio(0)

using namespace std;

int main() {
  fastio;
  int h, n;
  cin >> h >> n;
  long long map[31][31];
  fill(&map[0][0], &map[0][0] + 31 * 31, 0);
  int move[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
  queue<pair<int, int>> q;
  q.push(make_pair(h, h));
  map[h][h] = 1;
  while (!q.empty()) {
    pair<int, int> cur = q.front();
    q.pop();
    for (int i = 0; i < 4; i++) {
      pair<int, int> next =
          make_pair(cur.first + move[i][0], cur.second + move[i][1]);
      if (next.first < 0 || next.first > 30 || next.second < 0 ||
          next.second > 30)
        continue;
      if (next.second > next.first) continue;
      int current_dist = abs(cur.first - n) + abs(cur.second - n);
      int next_dist = abs(next.first - n) + abs(next.second - n);
      if (next_dist >= current_dist) continue;
      if (map[next.first][next.second] == 0) {
        q.push(next);
      }
      map[next.first][next.second] += map[cur.first][cur.second];
    }
  }
  cout << map[n][n] << "\n";
  return 0;
}