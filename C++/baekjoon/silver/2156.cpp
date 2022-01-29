#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(void)
{
 int n;
 vector<int> drink(10001, 0);
 vector<int> dp(10001, 0);
 cin >> n;
 int a = n / 3;
 for (int i = 1; i <= n; i++)
 {
  cin >> drink[i];
 }
 dp[1] = drink[1];
 dp[2] = drink[1] + drink[2];
 dp[3] = max(drink[2] + drink[3], max(drink[1] + drink[2], drink[1] + drink[3]));
 for (int i = 4; i <= n + 1; i++)
 {
  dp[i] = max(dp[i - 1], max(drink[i] + drink[i - 1] + dp[i - 3], drink[i] + dp[i - 2]));
 }
 cout << max(dp[n], dp[n + 1]) << "\n";
 return 0;
}