#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<vector<long long int>> memo(1002, (vector<long long int>(1002, 0)));
long long int binomial_cof(long long int n, long long int k)
{
 if (k == 0 || k == n)
  return memo[n][k] = 1;
 else if (memo[n][k] != 0)
  return memo[n][k] % 10007;
 else
  return memo[n][k] = (binomial_cof(n - 1, k - 1) % 10007) + (binomial_cof(n - 1, k) % 10007);
}
int main(void)
{
 long long int n, k;
 long long int answer;
 cin >> n >> k;
 cout << binomial_cof(n, k) % 10007 << "\n";
 return 0;
}