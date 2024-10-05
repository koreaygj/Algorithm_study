#include <iostream>
using namespace std;

// https://www.acmicpc.net/problem/1720
//  dp[n] = dp[n - 1] + dp[n - 2] * 2
//  홀수일때 대칭 = dp[(n - 1) / 2]
//  짝수일때 대칭 = dp[n / 2] +  dp[(n - 2) / 2] * 2
//  1. 대칭이 되지 않는 경우는 본래 대칭인 경우이므로
//  2. 대칭인 경우를 구해서 더한후 2로 나눠주면 풀이가능
//  dp[n] = dp[n - 1] + dp[n - 2] * 2
//  if even -> dp[n] = (dp[n] + dp[n / 2] + dp[(n - 2) / 2] * 2) / 2
//  if odd -> dp[n] = (dp[n] + dp[(n - 1) / 2 ] * 2) / 2

int solution(int n)
{
  int dp[32] = {};
  dp[0] = 1;
  dp[1] = 1;
  dp[2] = 3;
  for (int i = 3; i <= n; i++)
  {
    dp[i] = dp[i - 1] + dp[i - 2] * 2;
  }
  if (n % 2 == 1)
  {
    dp[n] = (dp[n] + dp[(n - 1) / 2]) / 2;
  }
  else
  {
    dp[n] = (dp[n] + dp[n / 2] + dp[n / 2 - 1] * 2) / 2;
  }
  return dp[n];
}

int main()
{
  int n;
  cin >> n;
  int result = solution(n);
  cout << result << "\n";
  return 0;
}
