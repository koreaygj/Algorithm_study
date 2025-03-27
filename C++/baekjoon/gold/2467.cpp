#include <limits.h>

#include <algorithm>
#include <iostream>
using namespace std;
int main() {
  int n;
  cin >> n;
  int liquid[n];
  for (int i = 0; i < n; i++) cin >> liquid[i];
  int left = 0;
  int right = n - 1;
  int abs_min = INT_MAX;
  pair<int, int> ans;
  while (left < right) {
    int tmp = liquid[left] + liquid[right];
    if (abs(tmp) <= abs_min) {
      ans = make_pair(left, right);
      abs_min = abs(tmp);
    }
    if (tmp < 0) {
      left++;
    } else {
      right--;
    }
  }
  cout << liquid[ans.first] << " " << liquid[ans.second] << "\n";
}