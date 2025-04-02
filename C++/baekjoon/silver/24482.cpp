#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>
#define fastio cin.tie(0)->ios::sync_with_stdio(0);
using namespace std;
vector<int> Trunk[100005];
int Depth[100005];
void dfs(int st, int cnt, int n) {
  Depth[st] = cnt;
  for (int i = 0; i < Trunk[st].size(); i++) {
    int next = Trunk[st][i];
    if (Depth[next] != -1) continue;
    dfs(next, cnt + 1, n);
  }
}
int main() {
  fastio;
  int n, m, r;
  cin >> n >> m >> r;
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    Trunk[a].push_back(b);
    Trunk[b].push_back(a);
  }
  memset(Depth, -1, sizeof(Depth));
  for (int i = 1; i <= n; i++) {
    sort(Trunk[i].begin(), Trunk[i].end(), greater<>());
  }
  dfs(r, 0, n);
  for (int i = 1; i <= n; i++) {
    cout << Depth[i] << "\n";
  }
}