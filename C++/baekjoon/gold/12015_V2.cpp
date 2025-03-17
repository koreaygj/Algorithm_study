#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int main() {
  int n;
  cin >> n;
  int arr[n];
  for (int i = 0; i < n; i++) cin >> arr[i];
  vector<int> seq;
  seq.push_back(0);
  for (int i = 0; i < n; i++) {
    if (seq.back() < arr[i])
      seq.push_back(arr[i]);
    else {
      int st = 0;
      int end = seq.size();
      while (st < end) {
        int mid = (st + end) / 2;
        if (seq[mid] < arr[i])
          st = mid + 1;
        else
          end = mid;
      }
      seq[end] = arr[i];
    }
  }
  cout << seq.size() - 1 << "\n";
  return 0;
}