#include <algorithm>
#include <iostream>
#include <queue>
#define mp(a, b) make_pair(a, b)
using namespace std;
// Black == 1 White == 2 Blank == 0
int Board[20][20];
int Visited[20][20];
int Score[3];
pair<int, int> Dir[4] = {mp(-1, 0), mp(1, 0), mp(0, -1), mp(0, 1)};
bool bfs(int n, int st_y, int st_x) {
  queue<pair<int, int> > q;
  q.push(make_pair(st_y, st_x));
  Visited[st_y][st_x] = true;
  int adjacent = 0;
  int cnt = 1;
  bool is_neutral = false;
  while (!q.empty()) {
    pair<int, int> cur = q.front();
    q.pop();
    for (int i = 0; i < 4; i++) {
      int next_y = cur.first + Dir[i].first;
      int next_x = cur.second + Dir[i].second;
      if (next_y <= 0 || next_y > n || next_x <= 0 || next_x > n ||
          Visited[next_y][next_x])
        continue;
      if (Board[next_y][next_x] == 0) {
        q.push(make_pair(next_y, next_x));
        Visited[next_y][next_x] = true;
        cnt++;
      } else {
        if (adjacent == 0) {
          adjacent = Board[next_y][next_x];
          // 인접한 점이 이전과 다르면 bfs 종료
        } else if (adjacent != Board[next_y][next_x]) {
          is_neutral = true;
        }
      }
    }
  }
  if (adjacent != 0 && !is_neutral) {
    Score[adjacent] += cnt;
  }
  return true;
}
int main() {
  int n, b, w;
  while (true) {
    cin >> n;
    if (n == 0) break;
    cin >> b >> w;
    // 전역  변수 초기화
    for (int i = 0; i <= n; i++) {
      for (int j = 0; j <= n; j++) {
        Board[i][j] = 0;
        Visited[i][j] = false;
      }
    }
    Score[1] = 0;
    Score[2] = 0;

    int y, x;
    for (int i = 0; i < b; i++) {
      cin >> y >> x;
      Board[y][x] = 1;
    }
    for (int i = 0; i < w; i++) {
      cin >> y >> x;
      Board[y][x] = 2;
    }
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        if (Board[i][j] == 0 && !Visited[i][j]) {
          bfs(n, i, j);
        }
      }
    }

    int ans = 0;
    ans = Score[2] - Score[1];
    if (ans == 0)
      cout << "Draw\n";
    else if (ans > 0)
      cout << "White wins by " << ans << "\n";
    else
      cout << "Black wins by " << -ans << "\n";
  }
}