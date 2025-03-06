#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;
// keyboard bind
char keyboard[3][10] = {{'Q', 'W', 'E', 'R', 'T', 'Y', 'U', 'I', 'O', 'P'},
                        {'A', 'S', 'D', 'F', 'G', 'H', 'J', 'K', 'L'},
                        {'Z', 'X', 'C', 'V', 'B', 'N', 'M'}};
pair<int, int> findStartIndex(char st) {
  for (int i = 0; i < 10; i++) {
    if (keyboard[0][i] == st) {
      return make_pair(0, i);
    }
  }
  for (int i = 0; i < 9; i++) {
    if (keyboard[1][i] == st) {
      return make_pair(1, i);
    }
  }
  for (int i = 0; i < 7; i++) {
    if (keyboard[2][i] == st) {
      return make_pair(2, i);
    }
  }
  return make_pair(-1, -1);
}
int bfs(char st, char next) {
  int cnt = 0;
  int move[6][2] = {{-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}};
  pair<int, int> st_index = findStartIndex(st);
  queue<pair<int, int> > q;
  int visited[3][10] = {0};
  visited[st_index.first][st_index.second] = 0;
  q.push(st_index);
  while (!q.empty()) {
    pair<int, int> st = q.front();
    q.pop();
    // 도착시
    if (keyboard[st.first][st.second] == next)
      return visited[st.first][st.second];
    for (int i = 0; i < 6; i++) {
      pair<int, int> next =
          make_pair(st.first + move[i][0], st.second + move[i][1]);
      // 예외처리
      if (next.first < 0 || next.first > 2 || next.second < 0) continue;
      if (next.first == 0 && next.second > 9) continue;
      if (next.first == 1 && next.second > 8) continue;
      if (next.first == 2 && next.second > 6) continue;
      if (visited[next.first][next.second] > 0) continue;
      visited[next.first][next.second] = visited[st.first][st.second] + 1;
      q.push(next);
    }
  }
  return cnt;
}
int main() {
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    string str;
    int ans = 1;
    cin >> str;
    char st = str[0];
    for (int i = 1; i < str.length(); i++) {
      char next = str[i];
      int move = bfs(st, next);
      // 움직임
      ans += move * 2;
      // 버튼 누르기
      ans++;
      st = next;
    }
    cout << ans << "\n";
  }
}