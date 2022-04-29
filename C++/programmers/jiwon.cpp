#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
vector<vector<int>> solution(int n, int m)
{
  vector<vector<int>> answer;
  int size = pow(n, m);
  for (int i = 0; i < size; i++)
  {
    int a = i / n;
    int b = i % n;
    answer.push_back({a, b});
  }
  return answer;
}
int main(void)
{
  int n, m;
  cin >> n >> m;
  int size = pow(n, m);
  vector<vector<int>> ans = solution(n, m);
  for (int i = 0; i < size; i++)
  {
    int a = i % m;
    cout << ans[i][a] << " ";
    if (a == m - 1)
      cout << "\n";
  }
  cout << size;
  return 0;
}