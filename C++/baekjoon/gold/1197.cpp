#include <algorithm>
#include <iostream>

using namespace std;
struct Trunk {
  int st;
  int end;
  int cost;
  Trunk(int st, int end, int cost) : st(st), end(end), cost(cost) {}
};
bool comp(Trunk a, Trunk b) { return a.cost < b.cost; }
class Tree {
  int v;
  int e;
  long long ans;
  int find(int x);
  bool union_parent(int x, int y);
  int parent[100001];
  vector<Trunk> node;

 public:
  void input();
  void findWeight();
  void print() { cout << ans << "\n"; }
};
void Tree::input() {
  cin >> v >> e;
  for (int i = 0; i < e; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    node.push_back(Trunk(a, b, c));
  }
  for (int i = 0; i < v + 1; i++) parent[i] = i;
  sort(node.begin(), node.end(), comp);
}
int Tree::find(int x) {
  if (parent[x] == x)
    return x;
  else {
    return parent[x] = find(parent[x]);
  }
}
bool Tree::union_parent(int x, int y) {
  if (x == y) {
    return true;
  } else {
    if (x < y)
      parent[y] = x;
    else
      parent[x] = y;
    return false;
  }
}
void Tree::findWeight() {
  for (int i = 0; i < node.size(); i++) {
    Trunk cur = node[i];
    int x = find(cur.st);
    int y = find(cur.end);
    if (x != y) {
      union_parent(x, y);
      ans += cur.cost;
    }
  }
}
int main(void) {
  cin.tie(NULL);
  cout.tie(NULL);
  ios::sync_with_stdio(false);
  Tree mst;
  mst.input();
  mst.findWeight();
  mst.print();
}