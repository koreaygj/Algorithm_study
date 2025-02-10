#include <iostream>
#include <vector>
using namespace std;
int partnerMatching(vector<int> minus, vector<int> plus) {
  int minus_index = 0;
  int plus_index = 0;
  int cnt = 0;
  while (minus_index < minus.size() && plus_index < plus.size()) {
    if (minus[minus_index] > plus[plus_index]) {
      cnt++;
      minus_index++;
      plus_index++;
    } else {
      minus_index++;
    }
  }
  return cnt;
}
int main() {
  int n;
  cin >> n;
  vector<int> man_plus;
  vector<int> man_min;
  vector<int> w_plus;
  vector<int> w_min;
  for (int i = 0; i < n; i++) {
    int tmp;
    cin >> tmp;
    if (tmp > 0)
      man_plus.push_back(tmp);
    else
      man_min.push_back(-tmp);
  }
  for (int i = 0; i < n; i++) {
    int tmp;
    cin >> tmp;
    if (tmp > 0)
      w_plus.push_back(tmp);
    else
      w_min.push_back(-tmp);
  }
  sort(man_plus.begin(), man_plus.end());
  sort(man_min.begin(), man_min.end());
  sort(w_plus.begin(), w_plus.end());
  sort(w_min.begin(), w_min.end());
  int ans = partnerMatching(man_min, w_plus) + partnerMatching(w_min, man_plus);
  cout << ans << "\n";
}