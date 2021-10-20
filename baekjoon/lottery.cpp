#include <iostream>
#include <vector>
using namespace std;
long long int combination(int a, int b)
{
  long long int comb = 1;
  for (int i = a; i > a - b; i--)
    comb *= i;
  for (int j = b; j > 0; j--)
    comb /= j;
  return comb;
}
double solution(int n, int m, int k)
{
  double per = 1;
  double size = 1;
  double win = 1;
  size = combination(n, m);
  for (int i = 1; i <= m - k; i++)
    win += combination(n - k, m - i);
  per = win / size;
  cout << size << " " << win << " " << per;
  return per;
}
int main(void)
{
  int n, m, k = 0;
  cin >> n >> m >> k;
  cout << solution(n, m, k);
  return 0;
}