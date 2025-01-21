#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
int Board[3][3];
bool Visited[3][3];
int N, M;
int MoveX[] = {0, 0, 1, -1};
int MoveY[] = {1, -1, 0, 0};
vector<int> dot_x;
vector<int> dot_y;
bool bfs(int st_x, int st_y, int cnt, int sum) {
  Visited[st_x][st_y] = true;
  dot_x.push_back(st_x);
  dot_y.push_back(st_y);
  if (cnt == M * 2 - 1) {
    return sum == N;
  }
  for (int i = 0; i < 4; i++) {
    int next_x = st_x + MoveX[i];
    int next_y = st_y + MoveY[i];
    bool result = false;
    if (next_x < 0 || next_x > 2 || next_y < 0 || next_y > 2 ||
        Visited[next_x][next_y])
      continue;
    // cnt 홀수 인 경우 계산
    if (cnt % 2 == 0) {
      int delta = (Board[st_x][st_y] == 0) ? Board[next_x][next_y]
                                           : -Board[next_x][next_y];
      sum += delta;
      result = bfs(next_x, next_y, cnt + 1, sum);
      sum -= delta;
    } else {
      result = bfs(next_x, next_y, cnt + 1, sum);
    }
    if (result) return true;
    dot_x.pop_back();
    dot_y.pop_back();
    Visited[next_x][next_y] = false;
  }
  return false;
}
void printVisitedBlock(bool result) {
  if (result) {
    cout << "1\n";
    for (int i = 0; i < M * 2 - 1; i++) {
      cout << dot_x[i] << " " << dot_y[i] << "\n";
    }
  } else
    cout << "0\n";
}
int main() {
  cin >> N >> M;
  for (int i = 0; i < 3; i++) {
    string s;
    cin >> s;
    for (int j = 0; j < s.size(); j++) {
      if (s[j] == '+') {
        Board[i][j] = 0;
      } else if (s[j] == '-') {
        Board[i][j] = -1;
      } else {
        Board[i][j] = s[j] - '0';
      }
    }
  }
  int st_x[] = {0, 0, 1, 2, 2};
  int st_y[] = {0, 2, 1, 0, 2};
  bool result = false;
  for (int i = 0; i < 5; i++) {
    memset(Visited, false, sizeof(Visited));
    dot_x = vector<int>();
    dot_y = vector<int>();
    result = bfs(st_x[i], st_y[i], 1, Board[st_x[i]][st_y[i]]);
    if (result) {
      break;
    }
  }
  printVisitedBlock(result);
}