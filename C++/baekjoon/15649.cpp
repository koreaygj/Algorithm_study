#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 8
using namespace std;
int n, m;
vector<int> input;
vector<int> ans;
vector<bool> vis;
void Print()
{
  for (int i = 0; i < ans.size(); i++)
    cout << ans[i] << " ";
  cout << "\n";
  return;
}
void DFS(int cnt)
{
  if (cnt == m)
  {
    Print();
    return;
  }

  for (int i = 0; i < n; i++)
  {
    if (vis[i])
      continue;
    vis[i] = true;
    ans.push_back(input[i]);
    DFS(cnt + 1);
    ans.pop_back();
    vis[i] = false;
  }
}
int main(void)
{
  cin >> n >> m;
  for (int i = 1; i <= n; i++)
  {
    input.push_back(i);
    vis.push_back(false);
  }
  DFS(0);
  return 0;
}