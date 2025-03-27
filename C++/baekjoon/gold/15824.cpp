#include <algorithm>
#include <iostream>
#define MOD 1000000007
using namespace std;
long long modPow(long long base, long long exp) {
  long long result = 1;
  base = base % MOD;
  while (exp > 0) {
    if (exp % 2 == 1) result = (result * base) % MOD;
    exp = exp >> 1;
    base = (base * base) % MOD;
  }
  return result;
}

int main() {
  int n;
  cin >> n;
  long long menu[n];
  for (int i = 0; i < n; i++) cin >> menu[i];
  sort(&menu[0], &menu[0] + n);
  long long pos = 0;
  long long neg = 0;
  for (int i = 0; i < n; i++) {
    pos += menu[n - i - 1] * modPow(2, n - i - 1);
    neg += menu[i] * modPow(2, n - i - 1);
    pos %= MOD;
    neg %= MOD;
  }

  cout << (pos % MOD + MOD - neg % MOD) % MOD << "\n";
}