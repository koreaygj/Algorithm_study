#include <algorithm>
#include <climits>
#include <iostream>
#include <queue>
#define fastio cin.tie(0)->ios::sync_with_stdio(0)

using namespace std;

int main() {
  fastio;
  int n, m;
  cin >> n >> m;

  vector<pair<int, int>> graph[n + 1];
  for (int i = 0; i < m; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    graph[a].push_back(make_pair(b, c));
    graph[b].push_back(make_pair(a, c));
  }

  vector<int> dist(n + 1, INT_MAX);
  dist[1] = 0;

  priority_queue<pair<int, int>, vector<pair<int, int>>,
                 greater<pair<int, int>>>
      pq;
  pq.push({0, 1});

  while (!pq.empty()) {
    int current_cost = pq.top().first;
    int current_node = pq.top().second;
    pq.pop();

    if (current_cost > dist[current_node]) {
      continue;
    }

    for (auto& edge : graph[current_node]) {
      int next_node = edge.first;
      int edge_cost = edge.second;
      int new_cost = current_cost + edge_cost;

      if (new_cost < dist[next_node]) {
        dist[next_node] = new_cost;
        pq.push({new_cost, next_node});
      }
    }
  }

  cout << dist[n] << endl;
  return 0;
}