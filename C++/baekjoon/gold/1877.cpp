#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
using namespace std;

map<int, int> PrimeFactorization(int m) {
  map<int, int> result;
  for (int i = 2; i <= sqrt(m); i++) {
    while (m % i == 0) {
      m /= i;
      result[i]++;
    }
  }
  if (m > 1) result[m]++;
  return result;
}

int main(void) {
  cin.tie(NULL);
  cout.tie(NULL);
  ios::sync_with_stdio(false);

  int m;
  cin >> m;

  int n_min, n_max, m_min, m_max;

  if (m < 3) {
    n_min = n_max = 1;
  } else {
    int a = m / 3;
    int b = m % 3;
    n_min = a + (b <= 1 ? 0 : 1);
    n_max = a + (b == 0 ? 0 : 1);
  }

  if (m == 1) {
    m_min = m_max = 1;
  } else {
    map<int, int> factorization = PrimeFactorization(m);
    m_max = 0;
    for (const auto& pair : factorization) {
      m_max += pair.second;
    }
    m_min = m_max;
    if (factorization.find(2) != factorization.end()) {
      m_min -= factorization[2] / 2;
    }
  }
  cout << n_max << " " << n_min << " " << m_max << " " << m_min << "\n";

  return 0;
}