#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
#define fastio cin.tie(0)->ios::sync_with_stdio(0)

using namespace std;

struct Person {
  int index;
  int line;
  int d;
  int h;
};

struct PersonComp {
  bool operator()(const Person &a, const Person &b) const {
    if (a.d == b.d) {
      if (a.h == b.h) return a.line > b.line;
      return a.h < b.h;
    }
    return a.d < b.d;
  }
};

int main() {
  fastio;
  int n, m, k;
  cin >> n >> m >> k;

  queue<Person> line[m];
  for (int i = 0; i < n; i++) {
    Person a;
    a.index = i, a.line = i % m;
    cin >> a.d >> a.h;
    line[i % m].push(a);
  }

  priority_queue<Person, vector<Person>, PersonComp> pq;
  for (int i = 0; i < m; i++) {
    if (line[i].empty()) continue;
    pq.push(line[i].front());
    line[i].pop();
  }

  int cnt = 0;
  while (cnt < n) {
    Person cur = pq.top();
    pq.pop();
    if (cur.index == k) break;
    if (!line[cur.line].empty()) {
      pq.push(line[cur.line].front());
      line[cur.line].pop();
    }
    cnt++;
  }

  cout << cnt << "\n";

  return 0;
}