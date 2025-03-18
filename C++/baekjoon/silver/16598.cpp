#include <algorithm>
#include <iostream>
using namespace std;
int main() {
  int n, p;
  cin >> n >> p;
  int days[n];
  for (int i = 0; i < n; i++) {
    cin >> days[i];
  }
  int left = 0;
  int right = 0;
  long long ans = p;
  while (right <= n) {
    int max = days[left] + p + right - left;
    int len = right - left;
    if (days[right] > max) {
      ans = p + len > ans ? p + len : ans;
      left++;
    } else {
      ans = p + len > ans ? p + len : ans;
      right++;
    }
  }
  cout << ans << "\n";
}