#include <algorithm>
#include <iostream>
using namespace std;

int findPair(int n, int m, int a[], int b[]) {
  sort(b, b + m);
  int ans = 0;

  for (int i = 0; i < n; i++) {
    int target = a[i];
    int st = 0, end = m - 1;
    int result = m;

    while (st <= end) {
      int mid = (st + end) / 2;
      if (b[mid] < target) {
        result = mid;
        st = mid + 1;
      } else {
        end = mid - 1;
      }
    }

    if (result < m) {
      ans += result + 1;
    }
  }

  return ans;
}

int main() {
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    int n, m;
    cin >> n >> m;
    int a[n];
    int b[m];
    for (int j = 0; j < n; j++) cin >> a[j];
    for (int j = 0; j < m; j++) cin >> b[j];
    int result = findPair(n, m, a, b);
    cout << result << "\n";
  }
}