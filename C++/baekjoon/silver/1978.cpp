#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
int solution(int m, vector<int> num)
{
  int answer = 0;
  bool flag;
  for (int i = 0; i < num.size(); i++)
  {
    flag = false;
    for (int j = 2; j <= sqrt(num[i]); j++)
    {
      if (num[i] % j == 0 || num[i] == 1)
      {
        flag = false;
        break;
      }
      else
        flag = true;
    }
    if (flag == true || num[i] == 2 || num[i] == 3)
    {
      answer++;
    }
  }
  return answer;
}
int main(void)
{
  int n, m = 0;
  cin >> n;
  cin.ignore();
  vector<int> num;
  for (int i = 0; i < n; i++)
  {
    cin >> m;
    num.push_back(m);
    cin.ignore();
  }
  cout << solution(m, num);
  return 0;
}