#include <iostream>
#include <vector>
using namespace std;
vector<int> solution(int n, vector<vector<int>> spec)
{
  vector<int> answer;
  for (int i = 0; i < n; i++)
  {
    int ncount = 1;
    for (int j = 0; j < n; j++)
    {
      if (i != j)
      {
        if (spec[i][0] < spec[j][0] && spec[i][1] < spec[j][1])
        {
          ncount++;
        }
      }
    }
    answer.push_back(ncount);
  }
  return answer;
}
int main(void)
{
  int n, x, y;
  vector<vector<int>> spec;
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    cin >> x >> y;
    spec.push_back({x, y});
  }
  vector<int> ans = solution(n, spec);
  for (int ans : ans)
    cout << ans << " ";
  return 0;
}