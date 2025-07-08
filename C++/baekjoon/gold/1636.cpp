#include <algorithm>
#include <iostream>
#include <vector>
#define fastio cin.tie(0)->ios_base::sync_with_stdio(0)
using namespace std;

int main() {
  fastio;
  int n;
  cin >> n;

  vector<pair<int, int>> ranges(n);
  for (int i = 0; i < n; i++) {
    cin >> ranges[i].first >> ranges[i].second;
  }

  vector<pair<int, int>> possible_ranges(n);
  int total_cost = 0;

  possible_ranges[0] = ranges[0];

  for (int i = 1; i < n; i++) {
    pair<int, int> prev = possible_ranges[i - 1];
    pair<int, int> cur = ranges[i];

    if (prev.second < cur.first) {
      total_cost += cur.first - prev.second;
      possible_ranges[i] = {cur.first, cur.first};
    } else if (cur.second < prev.first) {
      total_cost += prev.first - cur.second;
      possible_ranges[i] = {cur.second, cur.second};
    } else {
      int left = max(prev.first, cur.first);
      int right = min(prev.second, cur.second);
      possible_ranges[i] = {left, right};
    }
  }

  vector<int> stress_values(n);
  stress_values[n - 1] = possible_ranges[n - 1].first;

  for (int i = n - 2; i >= 0; i--) {
    int next_value = stress_values[i + 1];

    if (next_value >= possible_ranges[i].first &&
        next_value <= possible_ranges[i].second) {
      stress_values[i] = next_value;
    } else {
      if (next_value < possible_ranges[i].first) {
        stress_values[i] = possible_ranges[i].first;
      } else {
        stress_values[i] = possible_ranges[i].second;
      }
    }
  }

  cout << total_cost << "\n";
  for (int i = 0; i < n; i++) {
    cout << stress_values[i] << "\n";
  }

  return 0;
}