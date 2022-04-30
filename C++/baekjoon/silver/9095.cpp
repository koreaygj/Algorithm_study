#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int solution(int n)
{
    vector<int> dp(11, 0);
    dp[0] = 1;
    dp[1] = 2;
    dp[2] = 4;
    for(int i = 3; i < n; i++)
    {
        dp[i] = dp[i-3] + dp[i-2] + dp[i-1];
    }
    return dp[n-1];
}
int main(void)
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    for(int i = 0; i < t; i++){
    int n;
    cin >> n;
    cout << solution(n) << "\n";
    }
}