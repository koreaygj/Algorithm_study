#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 8
using namespace std;
int n, m;
vector<int> input;
vector<bool> vis;
void Print()
{
  for (int i = 0; i < n; i++)
    if (vis[i])
      cout << input[i] << " ";
  cout << "\n";
  return;
}
void DFS(int cnt, int num)
{
  if (cnt == m)
  {
    Print();
    return;
  }
  for (int i = num; i < n; i++)
  {
    if (vis[i])
      continue;
    vis[i] = true;
    DFS(cnt + 1, i + 1);
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
  DFS(0, 0);
  return 0;
}