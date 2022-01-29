#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int factorial(int n)
{
 if (n <= 1)
  return 1;
 return (factorial(n - 1) * n);
}
int main(void)
{
 int n, k;
 int answer;
 cin >> n >> k;
 answer = factorial(n) / factorial(k);
 answer /= factorial(n - k);
 cout << answer << "\n";
 return 0;
}