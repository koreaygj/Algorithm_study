#include <iostream>
#include <vector>
using namespace std;
int main(void)
{
  cin.tie(NULL);
  cout.tie(NULL);
  ios_base::sync_with_stdio(false);
  int n;
  cin >> n;
  vector<vector<int>> cost(n + 1, vector<int>(3, 0));
  vector<vector<int>> expen(n + 1, vector<int>(3, 0));
  for (int i = 1; i <= n; i++)
  {
    cin >> expen[i][0] >> expen[i][1] >> expen[i][2];
    cost[i][0] = min(cost[i - 1][1], cost[i - 1][2]) + expen[i][0];
    cost[i][1] = min(cost[i - 1][0], cost[i - 1][2]) + expen[i][1];
    cost[i][2] = min(cost[i - 1][0], cost[i - 1][1]) + expen[i][2];
  }
  cout << min(cost[n][0], min(cost[n][1], cost[n][2])) << "\n";
  return 0;
}