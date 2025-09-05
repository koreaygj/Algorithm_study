#include <algorithm>
#include <iostream>
#include <vector>
#define fastio cin.tie(0)->ios::sync_with_stdio(false)

using namespace std;

const int CAP = 1000000001;

int main() {
  fastio;
  vector<vector<long long int>> comb(201, vector<long long int>(101, 0));

  for (int i = 0; i <= 200; i++) {
    comb[i][0] = 1;
    if (i <= 100) {
      comb[i][i] = 1;
    }
  }

  for (int i = 0; i <= 200; i++) {
    for (int j = 1; j <= min(i - 1, 100); j++) {
      comb[i][j] = comb[i - 1][j - 1] + comb[i - 1][j];

      if (comb[i][j] > CAP) comb[i][j] = CAP;
    }
  }

  int n, m, k;
  cin >> n >> m >> k;

  if (k > comb[n + m][n]) {
    cout << "-1\n";
    return 0;
  }

  string ans = "";
  int length = n + m;
  for (int i = 0; i < length; i++) {
    if (n == 0) {
      ans += "z";
      m--;
      continue;
    } else if (m == 0) {
      ans += "a";
      n--;
      continue;
    }
    long long int skip_cnt = comb[n + m - 1][n - 1];

    if (skip_cnt >= k) {
      ans += "a";
      n--;
    } else {
      ans += "z";
      m--;
      k -= skip_cnt;
    }
  }

  cout << ans << "\n";

  return 0;
}