#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(void)
{
  int n;
  vector<vector<int>> input;
  cin >> n;
  vector<vector<int>> memo(n + 1, vector<int>(n, 0));
  for (int i = 0; i < n; i++)
  {
    vector<int> b(i + 1, 0);
    for (int j = 0; j < i + 1; j++)
    {
      cin >> b[j];
    }
    input.push_back(b);
  }
  memo[0][0] = input[0][0];
  for (int i = 0; i < n - 1; i++)
  {
    for (int j = 0; j < i + 1; j++)
    {
      if (memo[i + 1][j] < input[i + 1][j] + memo[i][j])
        memo[i + 1][j] = input[i + 1][j] + memo[i][j];
      if (memo[i + 1][j + 1] < input[i + 1][j] + memo[i][j])
        memo[i + 1][j + 1] = input[i + 1][j + 1] + memo[i][j];
    }
  }
  cout << *max_element(memo[n - 1].begin(), memo[n - 1].end()) << "\n";
  return 0;
}