#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
#define fastio cin.tie(0)->ios::sync_with_stdio(0)

using namespace std;

struct Route {
  int from;
  int to;
  int cost;
  int time;

  Route(int from, int to, int cost, int time)
      : from(from), to(to), cost(cost), time(time) {}

  bool operator<(const Route& other) const {
    if (cost == other.cost) return time > other.time;
    return cost > other.cost;
  }
};

int Parent[200005];

int find(int x) {
  if (Parent[x] == x) return x;
  return Parent[x] = find(Parent[x]);
}

void union_root(int x, int y) {
  x = find(x);
  y = find(y);
  if (x < y)
    Parent[y] = x;
  else
    Parent[x] = y;
}

int main() {
  fastio;
  int n, q;
  cin >> n >> q;
  for (int i = 1; i <= n; i++) Parent[i] = i;

  priority_queue<Route> trail_tracks;
  for (int i = 0; i < q; i++) {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    trail_tracks.push(Route(a, b, c, d));
  }

  long long int min_cost = 0, min_time = 0;
  int cnt = 0;
  while (!trail_tracks.empty()) {
    Route cur = trail_tracks.top();
    trail_tracks.pop();

    if (find(cur.from) == find(cur.to)) continue;
    min_cost += cur.cost;
    min_time = min_time > cur.time ? min_time : cur.time;

    union_root(cur.from, cur.to);
    cnt++;

    if (cnt == n - 1) break;
  }

  int st = Parent[1];
  bool is_possible = true;
  for (int i = 2; i <= n; i++) {
    if (st != find(i)) {
      is_possible = false;
      break;
    }
  }

  if (is_possible)
    cout << min_time << " " << min_cost << "\n";
  else
    cout << "-1\n";
  return 0;
}