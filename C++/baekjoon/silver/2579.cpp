#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(void)
{
 int n, count = 0;
 long long int answer = 0;
 vector<int> stair(301, 0);
 vector<int> dp(301, 0);
 cin >> n;
 for (int i = 1; i <= n; i++)
 {
  cin >> stair[i];
 }
 dp[1] = stair[1];
 dp[2] = max(stair[2], stair[1] + stair[2]);
 dp[3] = max(stair[1] + stair[3], stair[2] + stair[3]);
 for (int i = 3; i <= n; i++)
 {
  dp[i] = max(stair[i] + stair[i - 1] + dp[i - 3], stair[i] + dp[i - 2]);
 }
 cout << dp[n] << "\n";
 return 0;
}