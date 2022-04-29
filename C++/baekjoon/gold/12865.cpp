#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class stuck
{
public:
 int weight;
 int value;
};
int main(void)
{
 int n, k;
 vector<stuck> stk(101, {0, 0});
 vector<vector<int>> dp(101, vector<int>(100001, 0));
 vector<int> ans;
 ios::sync_with_stdio(false);
 cin.tie(NULL);
 cout.tie(NULL);
 cin >> n >> k;
 for (int i = 1; i <= n; i++)
  cin >> stk[i].weight >> stk[i].value;
 for (int i = 1; i <= n; i++)
 {
  for (int j = 1; j <= k; j++)
  {
   if (j - stk[i].weight >= 0)
    dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - stk[i].weight] + stk[i].value);
   else
    dp[i][j] = dp[i - 1][j];
  }
 }
 cout << dp[n][k] << "\n";
 return 0;
}