#include <iostream>
#include <vector>
#define fastIO    \
  cin.tie(NULL);  \
  cout.tie(NULL); \
  ios::sync_with_stdio(false);
using namespace std;
struct Road {
  int x;
  int y;
  int z;
};
bool comp(const Road& a, const Road& b) { return a.z < b.z; }
class Tree {
  int m;
  int n;
  long long int ans = 0;
  int parent[200001];
  vector<Road> node;
  void FindBest(int cnt);
  int Find(int x);
  bool Union(int x, int y);

 public:
  void Input(int m, int n);
  void Print();
};
void Tree::Input(int m, int n) {
  for (int i = 0; i < n; i++) {
    int x, y, z;
    cin >> x >> y >> z;
    node.push_back({x, y, z});
    node.push_back({y, x, z});
    ans += z;
  }
  for (int i = 0; i <= m; i++) parent[i] = i;
  sort(node.begin(), node.end(), comp);
  FindBest(0);
}
int Tree::Find(int x) {
  if (parent[x] == x)
    return x;
  else {
    int y = Find(parent[x]);
    return y;
  }
}
bool Tree::Union(int x, int y) {
  x = Find(x);
  y = Find(y);
  if (x == y)
    return true;
  else {
    if (x < y)
      parent[y] = x;
    else
      parent[x] = y;
    return false;
  }
}
void Tree::FindBest(int cnt) {
  for (int i = 0; i < node.size(); i++) {
    Road cur = node[i];
    if (Find(cur.x) != Find(cur.y)) {
      ans -= cur.z;
      cnt++;
      Union(cur.x, cur.y);
      if (cnt == n - 1) return;
    }
  }
}

void Tree::Print() { cout << ans << "\n"; }
int main() {
  fastIO;
  while (true) {
    Tree tree;
    int n, m;
    cin >> m >> n;
    if (n == 0 && m == 0) break;
    tree.Input(m, n);
    tree.Print();
  }
}