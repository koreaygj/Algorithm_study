#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int N;
int Rollercoaster[1001];
int findNextIndex(int index, vector<int> vec) {
  int st = 0;
  int end = vec.size();
  while (st < end) {
    int mid = (st + end) / 2;
    if (vec[mid] < Rollercoaster[index]) {
      st = mid + 1;
    } else {
      end = mid;
    }
  }
  return end;
}
int findLength(int index) {
  vector<int> right;
  vector<int> left;
  right.push_back(-1);
  left.push_back(-1);
  for (int i = index; i < N; i++) {
    if (right.back() < Rollercoaster[i]) {
      right.push_back(Rollercoaster[i]);
    } else {
      right[findNextIndex(i, right)] = Rollercoaster[i];
    }
  }
  for (int i = index; i >= 0; i--) {
    if (left.back() < Rollercoaster[i]) {
      left.push_back(Rollercoaster[i]);
    } else {
      left[findNextIndex(i, left)] = Rollercoaster[i];
    }
  }
  return right.size() + left.size() - 3;
}
int main() {
  cin >> N;
  for (int i = 0; i < N; i++) cin >> Rollercoaster[i];
  int ans = 0;
  for (int i = 0; i < N; i++) {
    int tmp = findLength(i);
    ans = tmp > ans ? tmp : ans;
  }
  cout << ans << "\n";
}