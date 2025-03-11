#include <algorithm>
#include <climits>
#include <iostream>
#include <queue>
using namespace std;

char Room[1001][1001];
int N, M;

struct Pos {
  int y, x;
};

struct Edge {
  Pos v;
  int w;
  bool operator<(const Edge& e) const { return this->w > e.w; }
};

const int dy[4] = {0, 1, 0, -1};
const int dx[4] = {1, 0, -1, 0};

int FindWay(Pos start, Pos end) {
  int dist[1001][1001];
  for (int i = 0; i < N; i++)
    for (int j = 0; j < M; j++) dist[i][j] = INT_MAX;

  priority_queue<Edge> pq;
  dist[start.y][start.x] = 0;
  pq.push({start, 0});

  while (!pq.empty()) {
    Pos cur = pq.top().v;
    int cost = pq.top().w;
    pq.pop();

    if (dist[cur.y][cur.x] < cost) continue;

    if (Room[cur.y][cur.x] == 'E') return cost;

    if (Room[cur.y][cur.x] == 'X') {
      int ny = cur.y + 1;
      int newCost = cost + 10;

      while (ny < N && Room[ny][cur.x] == 'X') {
        dist[ny][cur.x] = newCost;
        ny++;
      }

      if (ny < N && Room[ny][cur.x] != 'D' && dist[ny][cur.x] > newCost) {
        dist[ny][cur.x] = newCost;
        pq.push({{ny, cur.x}, newCost});
      }
      continue;
    }

    if (cur.y > 0 && Room[cur.y][cur.x] == 'L') {
      int ny = cur.y - 1;
      int newCost = cost + 5;

      if (Room[ny][cur.x] != 'D' && dist[ny][cur.x] > newCost) {
        dist[ny][cur.x] = newCost;
        pq.push({{ny, cur.x}, newCost});
      }
    }

    if (cur.y < N - 1 && Room[cur.y + 1][cur.x] == 'L') {
      int ny = cur.y + 1;
      int newCost = cost + 5;

      if (dist[ny][cur.x] > newCost) {
        dist[ny][cur.x] = newCost;
        pq.push({{ny, cur.x}, newCost});
      }
    }

    for (int i : {0, 2}) {
      int ny = cur.y + dy[i];
      int nx = cur.x + dx[i];

      if (ny < 0 || ny >= N || nx < 0 || nx >= M) continue;

      int newCost = cost + 1;

      if (Room[ny][nx] == 'D' || dist[ny][nx] <= newCost) continue;

      dist[ny][nx] = newCost;
      pq.push({{ny, nx}, newCost});
    }
  }

  return INT_MAX;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N >> M;
  Pos dodo = {-1, -1};
  Pos exit = {-1, -1};

  for (int i = 0; i < N; i++) {
    string tmp;
    cin >> tmp;
    for (int j = 0; j < M; j++) {
      Room[i][j] = tmp[j];
      if (Room[i][j] == 'E')
        exit = {i, j};
      else if (Room[i][j] == 'C')
        dodo = {i, j};
    }
  }

  int ans = FindWay(dodo, exit);
  if (ans != INT_MAX)
    cout << ans << "\n";
  else
    cout << "dodo sad\n";

  return 0;
}