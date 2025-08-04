#include <algorithm>
#include <iostream>
#include <queue>
#include <set>
#include <vector>
#define fastio cin.tie(0)->ios::sync_with_stdio(0)

using namespace std;

void simulation(int n, int k, int m) {
  deque<int> dq;
  for (int i = 1; i <= n; i++) {
    dq.push_back(i);
  }

  int cnt = 0;
  bool is_reverse = 0;
  while (!dq.empty()) {
    if (cnt != 0 && cnt % m == 0) is_reverse = !is_reverse;

    if (!is_reverse) {
      for (int i = 0; i < k - 1; i++) {
        dq.push_back(dq.front());
        dq.pop_front();
      }
    } else {
      for (int i = 0; i < k; i++) {
        dq.push_front(dq.back());
        dq.pop_back();
      }
    }

    cout << dq.front() << "\n";
    dq.pop_front();
    cnt++;
  }
}

int main() {
  fastio;
  int n, k, m;
  cin >> n >> k >> m;

  simulation(n, k, m);

  return 0;
}