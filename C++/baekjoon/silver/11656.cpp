#include <algorithm>
#include <climits>
#include <iostream>
#include <queue>
#define fastio cin.tie(0)->ios::sync_with_stdio(0)

using namespace std;

int main() {
  fastio;
  string s;
  cin >> s;
  vector<string> v;
  for (int i = 0; i < s.size(); i++) {
    v.push_back(s.substr(i));
  }
  sort(v.begin(), v.end());
  for (const auto a : v) cout << a << "\n";

  return 0;
}