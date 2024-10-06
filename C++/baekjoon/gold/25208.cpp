#include <iostream>
#include <queue>
#define FASTIO \
  cin.tie(0);  \
  cout.tie(0); \
  ios_base::sync_with_stdio(0);
using namespace std;
int N, M;
char Board[505][505] = {};
int DirY[4] = {-1, 1, 0, 0};
int DirX[4] = {0, 0, -1, 1};
int DirHole[4][6] = {{5, 4, 2, 3, 0, 1}, {4, 5, 2, 3, 1, 0}, {3, 2, 0, 1, 4, 5}, {2, 3, 1, 0, 4, 5}};
int Visited[505][505][6];
struct NODE
{
  int y;
  int x;
  int hole;
};

int bfs(int stY, int stX)
{
  queue<NODE> q;
  q.push((NODE){stY, stX, 0});
  Visited[stY][stX][0] = 1;
  if (Board[stY][stX] == 'R')
    return 0;

  while (!q.empty())
  {
    int y = q.front().y;
    int x = q.front().x;
    int hole = q.front().hole;
    q.pop();
    for (int i = 0; i < 4; i++)
    {
      int ny = y + DirY[i];
      int nx = x + DirX[i];
      int nh = DirHole[i][hole];
      if (ny < 1 || nx < 1 || ny > N || nx > M || Board[ny][nx] == '#')
        continue;
      if (Board[ny][nx] == 'R' && nh == 0)
        return Visited[y][x][hole];
      else if (Board[ny][nx] == 'R' && nh != 0)
        continue;
      if (Visited[ny][nx][nh])
        continue;
      Visited[ny][nx][nh] = Visited[y][x][hole] + 1;
      q.push((NODE){ny, nx, nh});
    }
  }
  return -1;
}
int main()
{
  FASTIO;
  int stY, stX;
  cin >> N >> M;
  for (int i = 1; i <= N; i++)
  {
    for (int j = 1; j <= M; j++)
    {
      cin >> Board[i][j];
      if (Board[i][j] == 'D')
      {
        stY = i;
        stX = j;
      }
    }
  }
  int ans = bfs(stY, stX);
  cout << ans << "\n";
  return 0;
}