#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int solution(vector<vector<int>> board, int n, int m)
{
  vector<int> ans;
  for (int j = 0; j <= n - m; j++)
  {
    for (int k = 0; k <= n - m; k++)
    {
      int sum = 0;
      for (int x = j; x < j + m; x++)
      {
        for (int y = k; y < k + m; y++)
        {
          sum += board[x][y];
        }
      }
      ans.push_back(sum);
    }
  }
  sort(ans.begin(), ans.end());
  return ans.back();
}
int main()
{
  int t;
  cin >> t;
  int n, m, a;
  int ans;
  for (int i = 1; i <= t; i++)
  {
    cin >> n >> m;
    vector<vector<int>> board(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < n; j++)
      {
        cin >> a;
        board[i][j] = a;
      }
      ans = solution(board, n, m);
    }
    cout << "#" << i << " " << ans << "\n";
  }
  return 0;
}
