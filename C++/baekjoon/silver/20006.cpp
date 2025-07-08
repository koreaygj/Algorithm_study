#include <algorithm>
#include <iostream>
#include <vector>
#define fastio cin.tie(0)->ios::sync_with_stdio(0);
using namespace std;
bool compareBySecond(const pair<int, string>& a, const pair<int, string>& b) {
  return a.second < b.second;
}
int main(void) {
  int p, m;
  cin >> p >> m;
  vector<vector<pair<int, string>>> room;
  for (int i = 0; i < p; i++) {
    pair<int, string> p;
    cin >> p.first >> p.second;
    if (room.empty()) {
      room.push_back({});
    }
    bool find_match = false;
    for (int i = 0; i < room.size(); i++) {
      if (room[i].size() >= m) continue;
      if (room[i].size() == 0 || p.first <= room[i][0].first + 10 &&
                                     room[i][0].first - 10 <= p.first) {
        room[i].push_back(p);
        find_match = true;
        break;
      }
    }
    if (!find_match) {
      room.push_back({});
      room.back().push_back(p);
    }
  }
  for (int i = 0; i < room.size(); i++) {
    if (room[i].size() >= m)
      cout << "Started!\n";
    else
      cout << "Waiting!\n";
    sort(room[i].begin(), room[i].end(), compareBySecond);
    for (const auto p : room[i]) cout << p.first << " " << p.second << "\n";
  }
  return 0;
}
