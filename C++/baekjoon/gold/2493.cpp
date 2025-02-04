#include <iostream>
#include <vector>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<pair<int, int> > tower;
  int answer[n];
  for (int i = 0; i < n; i++) {
    int tmp;
    cin >> tmp;
    while (!tower.empty() && tower.back().first < tmp) {
      tower.pop_back();
    }
    answer[i] = tower.empty() ? 0 : tower.back().second;
    tower.push_back(pair<int, int>(tmp, i + 1));
  }
  for (int i : answer) {
    cout << i << " ";
  }
  cout << "\n";
}