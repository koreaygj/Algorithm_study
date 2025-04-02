#include <algorithm>
#include <iostream>
#include <queue>
#define fastio cin.tie(0)->ios::sync_with_stdio(0)
using namespace std;
int bfs(long long &a, long long &b) {
  queue<pair<long long, long long>> q;
  q.push(make_pair(a, 1));
  while (!q.empty()) {
    pair<long long, long long> cur = q.front();
    q.pop();
    if (cur.first == b) return cur.second;
    if (cur.first > b) continue;
    q.push(make_pair(cur.first * 2, cur.second + 1));
    q.push(make_pair(cur.first * 10 + 1, cur.second + 1));
  }
  return -1;
}
int main() {
  long long a, b;
  cin >> a >> b;
  cout << bfs(a, b) << "\n";
}