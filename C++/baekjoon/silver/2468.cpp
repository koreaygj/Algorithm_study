#include <cstring>
#include <iostream>
#include <queue>
using namespace std;
bool Visited[101][101];
int Board[101][101];
int N;

void bfs(int st_y, int st_x, int rain) {
  queue<pair<int, int>> q;
  int move_y[] = {-1, 1, 0, 0};
  int move_x[] = {0, 0, -1, 1};
  q.push(make_pair(st_y, st_x));
  Visited[st_y][st_x] = true;
  while (!q.empty()) {
    pair<int, int> cur = q.front();
    q.pop();
    for (int i = 0; i < 4; i++) {
      pair<int, int> next =
          make_pair(cur.first + move_y[i], cur.second + move_x[i]);
      if (next.first < 0 || next.first >= N || next.second < 0 ||
          next.second >= N)
        continue;
      if (Visited[next.first][next.second] ||
          Board[next.first][next.second] <= rain)
        continue;
      q.push(next);
      Visited[next.first][next.second] = true;
    }
  }
}
int main() {
  cin >> N;
  int min = 101, max = 0;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cin >> Board[i][j];
      if (Board[i][j] > max)
        max = Board[i][j];
      else if (Board[i][j] < min)
        min = Board[i][j];
    }
  }
  int max_safe = 1;
  for (int i = min; i < max; i++) {
    int cnt = 0;
    for (int j = 0; j < N; j++) memset(Visited[j], false, N);
    for (int j = 0; j < N; j++) {
      for (int k = 0; k < N; k++) {
        if (Board[j][k] > i && !Visited[j][k]) {
          bfs(j, k, i);
          cnt++;
        }
      }
    }
    max_safe = cnt > max_safe ? cnt : max_safe;
  }
  cout << max_safe << "\n";
}