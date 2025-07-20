#include <algorithm>
#include <iostream>
#include <vector>
#define fastio cin.tie(0)->ios::sync_with_stdio(0)

using namespace std;

int main() {
  fastio;
  int n, q;
  cin >> n >> q;

  vector<int> pos(n);
  long long basicDistance = 0;

  for (int i = 0; i < n; i++) {
    cin >> pos[i];
    basicDistance += pos[i] - 1;
  }

  sort(pos.begin(), pos.end());

  vector<int> targets(q);
  int maxPos = 0;
  for (int i = 0; i < q; i++) {
    cin >> targets[i];
    maxPos = max(maxPos, targets[i]);
  }

  vector<long long> distance(maxPos + 1, 0);
  distance[1] = basicDistance;

  int left = 0;
  int right = n;
  int idx = 0;

  while (idx < n && pos[idx] == 1) {
    left++;
    right--;
    idx++;
  }

  for (int i = 2; i <= maxPos; i++) {
    distance[i] = distance[i - 1] + left - right;
    while (idx < n && pos[idx] == i) {
      left++;
      right--;
      idx++;
    }
  }

  for (int target : targets) {
    cout << distance[target] << "\n";
  }

  return 0;
}