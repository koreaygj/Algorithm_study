#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
#define INF 987654321;
using namespace std;
vector<pair<int, int>> Trunk[1001];
int Visited[1001];
struct Bus {
  int city;
  int cost;
  Bus(int city, int cost) : city(city), cost(cost) {}
  bool operator<(const Bus b) const { return this->cost > b.cost; }
};
bool comp(pair<int, int> a, pair<int, int> b) { return a.second < b.second; }
int dijkstra(int st, int end) {
  for (int i = 0; i <= 1000; i++) {
    Visited[i] = INF;
  }
  priority_queue<Bus> pq;
  pq.push(Bus(st, 0));
  Visited[st] = 0;
  while (!pq.empty()) {
    Bus cur = pq.top();
    pq.pop();
    if (cur.city == end) {
      return cur.cost;
    }
    if (cur.cost > Visited[cur.city]) continue;
    for (int i = 0; i < Trunk[cur.city].size(); i++) {
      Bus next =
          Bus(Trunk[cur.city][i].first, cur.cost + Trunk[cur.city][i].second);
      if (next.cost < Visited[next.city]) {
        Visited[next.city] = next.cost;
        pq.push(next);
      }
    }
  }
  return -1;
}
int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int a, b, cost;
    cin >> a >> b >> cost;
    Trunk[a].push_back(make_pair(b, cost));
  }
  int st, end;
  cin >> st >> end;
  cout << dijkstra(st, end) << "\n";
}