#include <math.h>

#include <algorithm>
#include <iostream>
using namespace std;
int Z(int n, int st, int r, int c) {
  if (n == 0) return st;
  int scale = pow(4, n - 1);
  int half = pow(2, n - 1);
  int quad = 0;
  if (r < half && c < half) {
    return Z(n - 1, st + scale * 0, r, c);
  } else if (r < half && c >= half) {
    return Z(n - 1, st + scale * 1, r, c - half);
  } else if (r >= half && c < half) {
    return Z(n - 1, st + scale * 2, r - half, c);
  } else if (r >= half && c >= half) {
    return Z(n - 1, st + scale * 3, r - half, c - half);
  }
  return 0;
}

int main() {
  int n, r, c;
  cin >> n >> r >> c;
  cout << Z(n, 0, r, c) << "\n";
}