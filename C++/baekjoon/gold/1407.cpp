#include <algorithm>
#include <climits>
#include <iostream>
#include <queue>
#define fastio cin.tie(0)->ios::sync_with_stdio(0)

using namespace std;

long long solution(long long n, long long max) {
  long long ans = 0, x;
  long long weight = 1;

  for (int i = 0; i < max; i++) {
    if (n == 0) break;
    if (n & 1)
      x = n / 2 + 1;
    else
      x = n / 2;
    ans += weight * x;
    n /= 2;
    weight *= 2;
  }
  return ans;
}

int main() {
  fastio;
  long long a, b;
  cin >> a >> b;

  long long tmp = b;
  long long max = 0;
  while (tmp > 0) {
    tmp /= 2;
    max++;
  }

  cout << solution(b, max) - solution(a - 1, max) << "\n";

  return 0;
}