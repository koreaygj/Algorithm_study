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
bool check2(int a, int b)
{
  if (a > b)
    return true;
  else
    return false;
}
int main(void)
{
  int n;
  int answer = 0;
  vector<int> arr(1001, 0);
  vector<int> dp(1001, 1);
  vector<int> dp2(1001, 1);
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
        dp[i] = 1 + dp[j];
    }
  }
  for (int i = n; i > 0; i--)
  {
    for (int j = i + 1; j <= n; j++)
    {
      if (check2(arr[i], arr[j]) == false)
        continue;
      if (dp2[j] + 1 > dp2[i])
        dp2[i] = 1 + dp2[j];
    }
  }
  // for (int i = 1; i <= n; i++)
  //   cout << i << ": " << dp[i] << " ";
  // cout << endl;
  // for (int i = 1; i <= n; i++)
  //   cout << i << ": " << dp2[i] << " ";
  for (int i = 1; i <= n; i++)
    dp[i] += dp2[i];
  cout << *max_element(dp.begin(), dp.end()) - 1 << "\n";
  return 0;
}