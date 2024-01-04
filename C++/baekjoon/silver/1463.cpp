#include <iostream>
#include <vector>
using namespace std;
vector<int> dp(1000001, 0);
int solution(int count, int n)
{
 if (count <= n)
 {
  if (count % 6 == 0)
   dp[count] = min(dp[count - 1], min(dp[count / 2], dp[count / 3])) + 1;
  else if (count % 2 == 0)
   dp[count] = min(dp[count - 1], dp[count / 2]) + 1;
  else if (count % 3 == 0)
   dp[count] = min(dp[count - 1], dp[count / 3]) + 1;
  else
   dp[count] = dp[count - 1] + 1;
  solution(count + 1, n);
 }
 if (count == 2)
  return dp[n];
}
int main(void)
{
 int n, count = 0;
 cin >> n;
 if (n == 1)
  dp[1] = 0;
 else
  solution(2, n);
 cout << dp[n] << "\n";
 return 0;
}