#include <algorithm>
#include <iostream>
#include <map>
#define fastio cin.tie(0)->ios::sync_with_stdio(0)
using namespace std;
int main() {
  fastio;
  int n;
  cin >> n;
  map<string, pair<string, int>> alias;
  map<string, int> check_valid;
  string ans[n];

  for (int i = 0; i < n; i++) {
    string st;
    cin >> st;

    if (alias.find(st) != alias.end()) {
      string num = to_string(alias[st].second);
      alias[st] = make_pair(st + num, alias[st].second + 1);
      ans[i] = st + num;
    } else {
      string tmp = "";
      for (int j = st.size(); j > 0; j--) {
        if (check_valid.find(st.substr(0, j)) == check_valid.end()) {
          tmp = st.substr(0, j);
        }
        check_valid.insert({st.substr(0, j), 1});
      }
      if (tmp.size() != 0) {
        ans[i] = tmp;
        alias.insert({st, make_pair(tmp, 2)});
      } else {
        ans[i] = st;
        alias.insert({st, make_pair(st, 2)});
      }
    }
  }
  for (const auto key : ans) cout << key << "\n";
}