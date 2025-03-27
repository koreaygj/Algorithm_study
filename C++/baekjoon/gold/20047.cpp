#include <iostream>
using namespace std;
int main() {
  int n, a, b;
  cin >> n;
  string A, B;
  A.resize(n + 1);
  B.resize(n + 1);
  for (int i = 1; i <= n; ++i) {
    cin >> A[i];
  }
  for (int i = 1; i <= n; ++i) {
    cin >> B[i];
  }
  cin >> a >> b;
  bool dp[10001][3];
  dp[0][0] = true;
  string C;
  C.reserve(n);
  ++a;
  ++b;
  for (int i = 1, j = 1; i <= n; ++i) {
    if (i != a && i != b) {
      C.push_back(A[i]);
    }
  }
  for (int i = 1; i <= n; ++i) {
    dp[i][0] = dp[i - 1][0] && (B[i] == C[i - 1]);
    dp[i][1] = (dp[i - 1][1] && (B[i] == C[i - 2])) ||
               (dp[i - 1][0] && (B[i] == A[a]));
    dp[i][2] = (dp[i - 1][2] && (B[i] == C[i - 3])) ||
               (dp[i - 1][1] && (B[i] == A[b]));
  }
  cout << (dp[n][2] ? "YES" : "NO") << '\n';

  return 0;
}