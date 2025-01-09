#include <iostream>
#include <vector>
using namespace std;

bool dfs(vector<int>* trunk, bool* visited, int cur, int e, int cnt) {
  if (cur == e) return true;
  visited[cur] = true;
  bool has_route = false;
  int trunk_size = 0;
  for (int i : trunk[cur]) {
    if (!visited[i]) {
      trunk_size++;
      if (dfs(trunk, visited, i, e, cnt + 1)) {
        has_route = true;
      }
    }
  }
  if (has_route) {
    if (cnt % 2 != 0) {
      return true;
    } else if (trunk_size == 1) {
      return true;
    }
  }
  return false;
}

int main(void) {
  int n, s, e;
  cin >> n >> s >> e;
  vector<int> trunk[n + 1];
  bool* visited = new bool[n + 1]();
  for (int i = 1; i < n; i++) {
    int a, b;
    cin >> a >> b;
    trunk[a].push_back(b);
    trunk[b].push_back(a);
  }
  if (dfs(trunk, visited, s, e, 1))
    cout << "First\n";
  else
    cout << "Second\n";
}