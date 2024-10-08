#include <iostream>
#include <vector>
#include <set>
#include <limits.h>
#include <math.h>
#include <algorithm>
#define FASTIO \
  cin.tie(0);  \
  cout.tie(0); \
  ios_base::sync_with_stdio(0);
using namespace std;
// https://www.acmicpc.net/problem/1438

int calRectangle(int minX, int maxX, int minY, int maxY)
{
  return (maxX - minX + 2) * (maxY - minY + 2);
}

int solution(int n, vector<int> dotX, vector<int> dotY)
{
  int answer = INT_MAX;
  set<int> levelSet(dotX.begin(), dotX.end());
  vector<int> xLevel(levelSet.begin(), levelSet.end());
  for (int i = 0; i < xLevel.size(); i++)
  {
    for (int j = 0; j < xLevel.size(); j++)
    {
      int cnt = 0;
      vector<int> selected;
      for (int k = 0; k < n; k++)
      {
        if (dotX[k] >= xLevel[i] && dotX[k] <= xLevel[j])
        {
          cnt++;
          selected.push_back(dotY[k]);
        }
      }
      if (cnt < n / 2)
        continue;
      sort(selected.begin(), selected.end());
      for (int k = 0; k <= cnt - n / 2; k++)
      {
        answer = min(answer, calRectangle(xLevel[i], xLevel[j], selected[k], selected[k + n / 2 - 1]));
      }
    }
  }
  return answer;
}

int main()
{
  FASTIO;
  int n;
  vector<int> dotX;
  vector<int> dotY;
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    int x, y;
    cin >> x >> y;
    dotX.push_back(x);
    dotY.push_back(y);
  }
  cout << solution(n, dotX, dotY) << "\n";
  return 0;
}