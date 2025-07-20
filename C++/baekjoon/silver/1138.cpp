#include <algorithm>
#include <iostream>
#include <vector>
#define fastio cin.tie(0)->ios::sync_with_stdio(0)

using namespace std;

int main() {
  fastio;
  int n;
  cin >> n;
  int arr[n];
  for (int i = 0; i < n; i++) cin >> arr[i];

  vector<int> ans;
  for (int i = n - 1; i >= 0; i--) {
    if (ans.size() == arr[i])
      ans.push_back(i + 1);
    else if (ans.size() >= arr[i]) {
      ans.push_back(0);
      for (int j = ans.size() - 1; j >= 0; j--) {
        if (j != 0) ans[j] = ans[j - 1];
        if (j == arr[i]) {
          ans[j] = i + 1;
          break;
        }
      }
    }
  }

  for (const auto num : ans) cout << num << " ";
  cout << "\n";
}