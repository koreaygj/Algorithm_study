#include <iostream>
#include <vector>
using namespace std;
vector<vector<vector<int>>> memo(51, vector<vector<int>>(51, vector<int>(51, 0)));
int solution(int a, int b, int c)
{
  int ans;
  if (a <= 0 || b <= 0 || c <= 0)
  {
    ans = 1;
    return ans;
  }
  if (memo[a][b][c] != 0)
    return memo[a][b][c];
  if (a > 20 || b > 20 || c > 20)
  {
    return solution(20, 20, 20);
  }
  else if (a < b && b < c)
  {
    ans = solution(a, b, c - 1) + solution(a, b - 1, c - 1) - solution(a, b - 1, c);
    memo[a][b][c] = ans;
    return ans;
  }
  else
  {
    ans = solution(a - 1, b, c) + solution(a - 1, b - 1, c) + solution(a - 1, b, c - 1) - solution(a - 1, b - 1, c - 1);
    memo[a][b][c] = ans;
    return ans;
  }
}
int main(void)
{
  int a, b, c;
  while (1)
  {
    a = 0, b = 0, c = 0;
    cin >> a >> b >> c;
    if (a == -1 && b == -1 && c == -1)
      break;
    cout << "w(" << a << ", " << b << ", " << c << ") = " << solution(a, b, c) << "\n";
  }
  return 0;
}