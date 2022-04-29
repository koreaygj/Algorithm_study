#include <iostream>
#include <vector>
using namespace std;
vector<int> memo(100001, 0);
int solution(int n)
{
 if (n <= 1)
  return n;
 if (memo[n] > 0)
  return memo[n];
 return memo[n] = (solution(n - 1) + solution(n - 2)) % 1234567;
}
int main(void)
{
 int n;
 cin >> n;
 cout << solution(n);
 return 0;
}