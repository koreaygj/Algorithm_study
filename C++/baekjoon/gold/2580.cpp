#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define Max 9
vector<vector<int>> input(Max, (vector<int>(Max, 0)));
int amount = 0;
class dot
{
public:
  int x;
  int y;
};
vector<dot> index;
bool flag = false;
bool check(dot index)
{
  int a = index.x / 3, b = index.y / 3;
  for (int i = 0; i < Max; i++)
  {
    if (input[index.x][i] == input[index.x][index.y] && index.y != i)
      return false;
    if (input[i][index.y] == input[index.x][index.y] && index.x != i)
      return false;
  }
  for (int i = a * 3; i < a * 3 + 3; i++)
  {
    for (int j = b * 3; j < b * 3 + 3; j++)
    {
      if (input[i][j] == input[index.x][index.y])
        if (i != index.x && j != index.y)
          return false;
    }
  }
  return true;
}
void solution(int count)
{
  if (amount == count)
  {
    flag = true;
    return;
  }
  for (int i = 1; i <= Max; i++)
  {
    input[index[count].x][index[count].y] = i;
    if (check(index[count]))
    {
      solution(count + 1);
    }
    if (flag == true)
      return;
  }
  input[index[count].x][index[count].y] = 0;
  return;
}
int main(void)
{
  for (int i = 0; i < Max; i++)
  {
    for (int j = 0; j < Max; j++)
    {
      cin >> input[i][j];
      if (input[i][j] == 0)
      {
        index.push_back({i, j});
        amount++;
      }
    }
  }
  solution(0);
  for (int i = 0; i < Max; i++)
  {
    for (int j = 0; j < Max; j++)
      cout << input[i][j] << " ";
    cout << "\n";
  }
  return 0;
}