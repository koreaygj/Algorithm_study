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
    int tmp = 0;
    for (int j = 0; j < (b - a + 1) / 2; j++) {
      tmp = bucket[a + j];
      bucket[a + j] = bucket[b - j];
      bucket[b - j] = tmp;
    }
  }
  for (int i = 1; i <= n; i++) cout << bucket[i] << " ";
  cout << "\n";
}