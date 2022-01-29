#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
int main(void)
{
 int n;
 vector<int> num(100001, 0);
 vector<int> dp(100001, 0);
 cin >> n;
 for (int i = 1; i <= n; i++)
 {
  cin >> num[i];
  dp[i] = num[i];
 }
 for (int i = 2; i <= n; i++)
 {
  if (dp[i] < dp[i] + dp[i - 1])
   dp[i] = dp[i] + dp[i - 1];
 }
 cout << *max_element(dp.begin() + 1, dp.begin() + 1 + n) << "\n";
 return 0;
}