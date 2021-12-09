#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool check(int a, int b)
{
 if (a < b)
  return true;
 else
  return false;
}
int main(void)
{
 int n;
 vector<int> arr(1001, 0);
 vector<int> dp(1001, 1);
 cin >> n;
 for (int i = 1; i <= n; i++)
  cin >> arr[i];
 for (int i = 1; i <= n; i++)
 {
  for (int j = i - 1; j > 0; j--)
  {
   if (check(arr[j], arr[i]) == false)
    continue;
   if (dp[j] + 1 > dp[i])
   {
    // cout << i << " " << j << " " << 1 + dp[j] << endl;
    dp[i] = 1 + dp[j];
   }
  }
  // cout << i << ": " << dp[i] << " ";
 }
 sort(dp.begin(), dp.end());
 cout << dp.back() << "\n";
 return 0;
}