#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n;
vector<vector<int>> table;
vector<int> index;
vector<int> ans;
int cal()
{
  vector<int> start;
  vector<int> link;
  int sum1 = 0, sum2 = 0;
  for (int i = 0; i < n; i++)
  {
    if (index[i] == 1)
      start.push_back(i);
    else
      link.push_back(i);
  }
  for (int i = 0; i < n / 2; i++)
  {
    for (int j = i + 1; j < n / 2; j++)
    {
      sum1 += table[start[i]][start[j]] + table[start[j]][start[i]];
      sum2 += table[link[i]][link[j]] + table[link[j]][link[i]];
    }
  }
  ans.push_back(abs(sum1 - sum2));
  return 0;
}
void solution(int count, int prev)
{
  if (count == n / 2)
  {
    cal();
    return;
  }
  for (int i = prev + 1; i < n; i++)
  {
    if (index[i] == 1)
      continue;
    index[i] = 1;
    solution(count + 1, i);
    index[i] = 0;
  }
}
int main(void)
{
  cin >> n;
  vector<vector<int>> size(n, vector<int>(n, 0));
  table = size;
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      cin >> table[i][j];
    }
    index.push_back(0);
  }
  solution(0, 0);
  sort(ans.begin(), ans.end());
  cout << ans[0] << "\n";
  return 0;
}
