#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<int> time(n);
  vector<int> period(n);
  vector<long long> chaos(n);
  for (int i = 0; i < n; i++) cin >> time[i];
  for (int i = 0; i < n; i++) cin >> period[i];
  for (int i = 0; i < n; i++) cin >> chaos[i];
  long long memo[n];
  memo[0] = chaos[0];
  for (int i = 1; i < n; i++) {
    int target = time[i] - period[i];
    int before = lower_bound(time.begin(), time.begin() + i + 1, target) -
                 time.begin() - 1;
    memo[i] = max(memo[i - 1], chaos[i]);
    if (before >= 0) memo[i] = max(memo[i], memo[before] + chaos[i]);
  }
  cout << memo[n - 1] << "\n";
}