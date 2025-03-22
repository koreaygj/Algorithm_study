#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int N;
int Parent[100005];

struct Log {
  int st_x;
  int end_x;
  int y;
  int index;
};
bool compare(const Log& a, const Log& b) {
  if (a.st_x != b.st_x) {
    return a.st_x < b.st_x;
  } else {
    return a.end_x < b.end_x;
  }
}
int find(int a) {
  if (a == Parent[a]) return a;
  return Parent[a] = find(Parent[a]);
}
void unionLog(int a, int b) {
  int a_pt = find(a);
  int b_pt = find(b);
  if (a_pt == b_pt) return;
  Parent[b_pt] = a_pt;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int q;
  cin >> N >> q;
  vector<Log> logs(N);
  for (int i = 0; i < N; i++) {
    cin >> logs[i].st_x >> logs[i].end_x >> logs[i].y;
    logs[i].index = i;
    Parent[i] = i;
  }
  sort(logs.begin(), logs.end(), compare);
  int currentEnd = logs[0].end_x;
  int lastGroup = logs[0].index;
  for (int i = 1; i < N; i++) {
    if (logs[i].st_x <= currentEnd) {
      unionLog(lastGroup, logs[i].index);
      if (logs[i].end_x > currentEnd) {
        currentEnd = logs[i].end_x;
      }
    } else {
      currentEnd = logs[i].end_x;
      lastGroup = logs[i].index;
    }
  }
  for (int i = 0; i < q; i++) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    if (find(a) == find(b)) {
      cout << "1\n";
    } else {
      cout << "0\n";
    }
  }

  return 0;
}