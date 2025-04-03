#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#define fastio cin.tie(0)->ios::sync_with_stdio(0)
using namespace std;
int Board[6][6];
struct Point {
  int y;
  int x;
  int cnt;
  int bit_visited;
  Point(int y, int x, int cnt, int bit_visited)
      : y(y), x(x), cnt(cnt), bit_visited(bit_visited) {}
};

int bfs(int r, int c) {
  int move_y[4] = {-1, 1, 0, 0};
  int move_x[4] = {0, 0, -1, 1};
  queue<Point> q;
  int visited[6][6][64];
  fill(&visited[0][0][0], &visited[0][0][0] + 6 * 6 * 64, false);
  int initial_bit = 0;
  if (Board[r][c] >= 1 && Board[r][c] <= 6)
    initial_bit = (1 << (Board[r][c] - 1));
  Point p = Point(r, c, 0, initial_bit);
  q.push(p);
  visited[r][c][initial_bit] = true;
  int all_visited = 63;
  while (!q.empty()) {
    Point cur = q.front();
    q.pop();
    if (all_visited == cur.bit_visited) {
      return cur.cnt;
    }
    for (int i = 0; i < 4; i++) {
      int next_y = cur.y + move_y[i];
      int next_x = cur.x + move_x[i];
      int next_bit = cur.bit_visited;
      if (Board[next_y][next_x] >= 1 && Board[next_y][next_x] <= 6) {
        next_bit |= (1 << (Board[next_y][next_x] - 1));
      }
      if (next_y < 0 || next_y >= 5 || next_x < 0 || next_x >= 5 ||
          Board[next_y][next_x] == -1)
        continue;
      if (visited[next_y][next_x][next_bit]) continue;
      Point next = Point(next_y, next_x, cur.cnt + 1, next_bit);
      q.push(next);
      visited[next_y][next_x][next_bit] = true;
    }
  }
  return -1;
}
int main() {
  fastio;
  int r, c;
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) cin >> Board[i][j];
  }
  cin >> r >> c;
  cout << bfs(r, c) << "\n";
}