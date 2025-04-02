#include <iostream>
#include <queue>
#include <vector>
#define fastio cin.tie(0)->ios::sync_with_stdio(0)
using namespace std;
vector<int> Trunk[101];
int dfs(int st, int end) {
  bool visited[101] = {false};
  queue<pair<int, int>> q;
  q.push(make_pair(st, 0));
  int cnt = 1;
  while (!q.empty()) {
    pair<int, int> cur = q.front();
    if (cur.first == end) return cur.second;
    q.pop();
    for (int i = 0; i < Trunk[cur.first].size(); i++) {
      pair<int, int> next = make_pair(Trunk[cur.first][i], cur.second + 1);
      if (visited[next.first]) continue;
      cnt++;
      q.push(next);
      visited[next.first] = true;
    }
  }
  return -1;
}
int main() {
  fastio;
  int n;
  int st, end;
  cin >> n >> st >> end;
  int m;
  cin >> m;
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    Trunk[a].push_back(b);
    Trunk[b].push_back(a);
  }
  cout << dfs(st, end) << "\n";
}