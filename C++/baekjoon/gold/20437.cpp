#include <math.h>

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#define fastio cin.tie(0)->ios::sync_with_stdio(0)
using namespace std;

int main() {
  fastio;
  int t;
  cin >> t;

  for (int i = 0; i < t; i++) {
    string st;
    int k;
    cin >> st >> k;
    vector<int> alpha[26];
    for (int j = 0; j < st.size(); j++) {
      alpha[st[j] - 'a'].push_back(j);
    }

    int ans_min = 10001;
    int ans_max = 0;
    for (int j = 0; j < 26; j++) {
      if (alpha[j].size() < k) continue;
      for (int index = 0; index < alpha[j].size(); index++) {
        if (index + k > alpha[j].size()) break;
        int tmp = alpha[j][index + k - 1] - alpha[j][index] + 1;
        ans_min = (tmp < ans_min) ? tmp : ans_min;
        ans_max = (tmp > ans_max) ? tmp : ans_max;
      }
    }
    if (ans_min == 10001 && ans_max == 0)
      cout << "-1\n";
    else
      cout << ans_min << " " << ans_max << "\n";
  }
  return 0;
}