#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;
bool decimal(int a)
{
  for (int i = 2; i <= sqrt(a); i++)
  {
    if (a % i == 0)
      return 0;
  }
  return 1;
}
vector<vector<int>> solution(int n, vector<int> a)
{
  vector<vector<int>> answer;
  int k = 0;
  for (int i = 0; i < *max_element(a.begin(), a.end()); i++)
  {
    k = a[i] / 2;
    for (int j = k; j > 0; j--)
    {
      if (decimal(j) == 1 && decimal(k) == 1)
      {
        answer.push_back({j, k});
        break;
      }
      k++;
    }
  }
  return answer;
}
int main(void)
{
  int n, num;
  vector<vector<int>> ans;
  vector<int> a;
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    cin >> num;
    cin.ignore();
    a.push_back(num);
  }
  ans = solution(n, a);
  for (int i = 0; i < n; i++)
  {
    cout << ans[i][0] << " " << ans[i][1] << "\n";
  }
  return 0;
}