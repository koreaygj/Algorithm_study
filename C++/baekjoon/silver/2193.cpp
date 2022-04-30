#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;
int solution(int n)
{
    vector<int> dp(91, 0);
    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 2;
    for(int i = 3;i < n; i++)
    {
        dp[i] = dp[i-1] + dp[i-2];
    }
    return dp[n-1];
}
int main(void)
{
    int n;
    cin >> n;
    cout << solution(n) << "\n";
}