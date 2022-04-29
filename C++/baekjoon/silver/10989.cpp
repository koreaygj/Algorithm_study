#include <iostream>
#include <vector>
using namespace std;
int main(void)
{
  cin.tie(NULL);
  cout.tie(NULL);
  ios_base::sync_with_stdio(false);
  int n;
  int ans[10001] = {0};
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    int a;
    cin >> a;
    ans[a]++;
  }
  for (int j = 1; j < 10001; j++)
  {
    if (ans[j] != 0 && n != 0)
    {
      for (int k = 0; k < ans[j]; k++)
      {
        cout << j << " ";
        n--;
      }
    }
    if (n == 0)
      break;
  }
  return 0;
}