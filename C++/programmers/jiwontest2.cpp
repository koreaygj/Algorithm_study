#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;
vector<string> solution(vector<string> grid, bool clockwise)
{
  vector<string> answer;
  string s;
  int count = 0;
  if (clockwise == true)
  {
    count = 0;
    for (int i = grid.size() - 1; i >= 0; i--)
    {
      s = grid[i].front();
      grid[i] = grid[i].substr(1, grid[i].size() - 1);
      if (count != 0)
      {
        for (int j = 1; j <= count / 2; j++)
        {
          s += grid[i + j].front();
          grid[i + j] = grid[i + j].substr(1, grid[i + j].size() - 1);
          s += grid[i + j][0];
          grid[i + j] = grid[i + j].substr(1, grid[i + j].size() - 1);
        }
      }
      sort(s.begin(), s.end(), greater<>());
      answer.push_back(s);
      count += 2;
    }
  }
  else
  {
    count = 0;
    for (int i = grid.size() - 1; i >= 0; i--)
    {
      s = grid[i].back();
      grid[i] = grid[i].substr(0, grid[i].size() - 1);
      if (count != 0)
      {
        for (int j = 1; j <= count / 2; j++)
        {
          s += grid[i + j].back();
          grid[i + j] = grid[i + j].substr(0, grid[i + j].size() - 1);
          s += grid[i + j].back();
          grid[i + j] = grid[i + j].substr(0, grid[i + j].size() - 1);
        }
      }
      answer.push_back(s);
      count += 2;
    }
  }
  return answer;
}
int main(void)
{
  vector<string> grid = {"A", "MAN", "DRINK", "WATER11"};
  bool clockwise = false;
  vector<string> ans = solution(grid, clockwise);
  for (int i = 0; i < ans.size(); i++)
  {
    cout << ans[i] << " ";
  }
  return 0;
}