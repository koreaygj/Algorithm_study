#include <iostream>
#include <queue>
using namespace std;
int Trunk[101][101];
int Memo[101][101];
void bfs(int n, int st) {
  bool visited[101] = {false};
  queue<int> q;
  q.push(st);
  while (!q.empty()) {
    int cur = q.front();
    q.pop();
    for (int i = 0; i < n; i++) {
      if (visited[i] || Trunk[cur][i] == 0) continue;
      visited[i] = true;
      q.push(i);
      Memo[st][i] = 1;
    }
  }
}
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      Memo[i][j] = 0;
      cin >> Trunk[i][j];
    }
  }
  for (int i = 0; i < n; i++) {
    bfs(n, i);
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cout << Memo[i][j] << " ";
    }
    cout << "\n";
  }
}