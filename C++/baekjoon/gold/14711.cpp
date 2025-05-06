#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
string board[1010];
bool check[1010][1010];
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};
int n;

void flip(int x, int y) {
  check[x][y] = true;
  if (board[x][y] == '#')
    board[x][y] = '.';
  else
    board[x][y] = '#';

  for (int i = 0; i < 4; i++) {
    int nx = x + dx[i];
    int ny = y + dy[i];
    if (0 <= nx && nx < n && 0 <= ny && ny < n) {
      if (board[nx][ny] == '#')
        board[nx][ny] = '.';
      else
        board[nx][ny] = '#';
    }
  }
}
int main() {
  cin >> n;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) board[i] += '.';

  string st;
  cin >> st;
  for (int i = 0; i < n; i++) {
    if (st[i] == '#') flip(0, i);
  };
  for (int i = 1; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (board[i - 1][j] == '#' && !check[i - 1][j])
        flip(i, j);
      else if (board[i - 1][j] == '.' && check[i - 1][j])
        flip(i, j);
    }
  }

  for (int i = 0; i < n; i++) {
    cout << board[i] << endl;
  }

  return 0;
}