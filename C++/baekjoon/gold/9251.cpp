#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
int main(void)
{
 // ios::sync_with_stdio(false);
 // cin.tie(NULL);
 // cout.tie(NULL);
 string a;
 string b;
 cin >> a;
 cin >> b;
 if (a.size() > b.size())
  swap(a, b);
 vector<vector<int>> dp(1001, vector<int>(1001, 0));
 for (int i = 1; i <= a.size(); i++)
 {
  for (int j = 1; j <= b.size(); j++)
  {
   if (a[i - 1] == b[j - 1])
    dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + 1);
   else
    dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
  }
 }
 cout << dp[a.size()][b.size()] << "\n";
 return 0;
}