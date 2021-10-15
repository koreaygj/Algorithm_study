#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve)
{
  int answer = 0;
  vector<int> index(n + 1, 0);
  sort(lost.begin(), lost.end());
  sort(reserve.begin(), reserve.end());
  for (int i = 0; i < lost.size(); i++)
  {
    index[lost[i]] = 1;
  }
  for (int i = 0; i < reserve.size(); i++)
  {
    if (index[reserve[i]] == 1)
      index[reserve[i]] = 0;
    else if (index[reserve[i] - 1] != 0 && reserve[i] - 1 >= 0)
      index[reserve[i] - 1] = 0;
    else if (index[reserve[i] + 1] != 0 && reserve[i] + 1 < n)
      index[reserve[i] + 1] = 0;
  }
  for (int i = 1; i <= n; i++)
  {
    if (index[i] == 0)
    {
      cout << i << " ";
      answer++;
    }
  }
  return answer;
}
int main(void)
{
  vector<int> lost = {2, 3, 4};
  vector<int> reserve = {1, 2, 3};
  int n = 5;
  cout << solution(n, lost, reserve);
  return 0;
}