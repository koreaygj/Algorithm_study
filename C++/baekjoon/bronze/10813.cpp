#include <iostream>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  int bucket[n + 1];
  for (int i = 1; i <= n; i++) bucket[i] = i;
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    int tmp = bucket[b];
    bucket[b] = bucket[a];
    bucket[a] = tmp;
  }
  for (int i = 1; i <= n; i++) cout << bucket[i] << " ";
  cout << "\n";
}