#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int gcf(int a, int b)
{
 if (b == 0)
  return a;
 return gcf(b, a % b);
}
int main(void)
{
 int n;
 cin >> n;
 vector<int> rds(n, 0);
 for (int i = 0; i < n; i++)
 {
  cin >> rds[i];
 }
 for (int i = 1; i < n; i++)
 {
  int m, n;
  int i_gcf;
  if (rds[0] < rds[i])
   i_gcf = gcf(rds[i], rds[0]);
  else
   i_gcf = gcf(rds[0], rds[i]);
  n = rds[0] / i_gcf;
  m = rds[i] / i_gcf;
  cout << n << "/" << m << "\n";
 }
 return 0;
}
