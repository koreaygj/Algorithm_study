#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
using namespace std;
int main() {
  int n;
  cin >> n;
  map<double, int> slope;
  for (int i = 0; i < n; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    double tmp = (double)a / b;
    if (slope.find(tmp) != slope.end())
      slope[tmp]++;
    else
      slope[tmp] = 1;
  }
  vector<int> counts;
  for (auto [key, value] : slope) {
    counts.push_back(value);
  }
  long long ans = 0;
  int prefix_sum = 0;
  for (int count : counts) {
    ans += prefix_sum * count;
    prefix_sum += count;
  }

  cout << ans << "\n";
}