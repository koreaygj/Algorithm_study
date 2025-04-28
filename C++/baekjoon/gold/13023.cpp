#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
vector<int> Trunk[2001];
bool visited[2001];
bool Ans = false;
void backTrack(int st, int cnt) {
  if (cnt == 5) {
    Ans = true;
    return;
  }
  for (int i = 0; i < Trunk[st].size(); i++) {
    int next = Trunk[st][i];
    if (!visited[next]) {
      visited[next] = true;
      backTrack(next, cnt + 1);
      visited[next] = false;
    }
  }
}
int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    Trunk[a].push_back(b);
    Trunk[b].push_back(a);
  }
  for (int i = 0; i < n; i++) {
    if (Ans) break;
    visited[i] = true;
    backTrack(i, 1);
    visited[i] = false;
  }
  cout << (Ans ? 1 : 0) << "\n";
  return 0;
}