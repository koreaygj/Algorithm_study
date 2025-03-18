#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
vector<int> Trunk[100001];
int Node[100001];
long long int calSum(int index) {
  long long int sum = 0;
  if (Trunk[index].size() == 0) return Node[index];
  for (int i = 0; i < Trunk[index].size(); i++) {
    int next_index = Trunk[index][i];
    long long int tmp = calSum(next_index);
    if (tmp > 0) sum += tmp;
  }
  return sum + Node[index];
}
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n - 1; i++) {
    int p, c;
    cin >> p >> c;
    Trunk[p].push_back(c);
  }
  for (int i = 0; i < n; i++) {
    cin >> Node[i];
  }
  long long int ans = calSum(0);
  cout << ans << "\n";
}