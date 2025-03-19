#include <cstring>
#include <iostream>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  int bucket[n + 1];
  memset(bucket, 0, sizeof(bucket));
  for (int i = 0; i < m; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    for (int j = a; j <= b; j++) bucket[j] = c;
  }
  for (int i = 1; i <= n; i++) {
    cout << bucket[i] << " ";
  }
  cout << "\n";
}