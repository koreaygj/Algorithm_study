#include <iostream>
#include <vector>
using namespace std;
int solution(int x, int y)
{
  long long int move = 0, point = 0;
  int count = 0;
  move = y - x;
  int j = 1;
  count = 0;
  point = 1;
  while (move - point != 0)
  {
    move -= j;
    if (j + 1 > 0 && move - point - j - 1 >= 0)
    {
      j++;
      point += j;
    }
    else if (j > 0 && move - point >= 0)
      j;
    else if (j - 1 > 0 && move - point + j >= 0)
    {
      point -= j;
      j--;
    }
    count++;
    // cout << move << " " << point << " " << j;
    // string n;
    // cin >> n;
    // if (n == "q")
    //   break;
  }
  cout << "\n";
  count += j;
  return count;
}
int main(void)
{
  int n;
  cin >> n;
  int x, y = 0;
  vector<int> ans;
  for (int i = 0; i < n; i++)
  {
    cin >> x >> y;
    cin.ignore();
    ans.push_back(solution(x, y));
  }
  for (int i = 0; i < n; i++)
    cout << ans[i] << "\n";
  return 0;
}