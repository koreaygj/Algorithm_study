#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

#define fastio cin.tie(0)->ios::sync_with_stdio(0)

using namespace std;

int main() {
  fastio;
  int w_len, s_len;
  string w, s;
  cin >> w_len >> s_len >> w >> s;

  unordered_map<char, int> target;
  for (char c : w) {
    target[c]++;
  }

  int cnt = 0;

  unordered_map<char, int> window;
  for (int i = 0; i < w_len; i++) {
    window[s[i]]++;
  }
  if (window == target) cnt++;

  for (int i = w_len; i < s_len; i++) {
    window[s[i]]++;
    char prev = s[i - w_len];
    window[prev]--;
    if (window[prev] == 0) window.erase(prev);

    if (window == target) cnt++;
  }

  cout << cnt << "\n";
  return 0;
}