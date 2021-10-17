#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums)
{
  vector<int> answer;
  int pos = 0;
  int result = 0;
  for (int i = 0; i < lottos.size(); i++)
  {
    if (lottos[i] == 0)
      pos++;
    for (int j = 0; j < win_nums.size(); j++)
    {
      if (lottos[i] == win_nums[j])
      {
        result++;
        break;
      }
    }
  }
  result += pos;
  for (int k = 0; k < 2; k++)
  {
    if (result >= 2)
      answer.push_back(7 - result);
    else
      answer.push_back(6);
    result -= pos;
  }
  return answer;
}
int main(void)
{
  vector<int> lottos = {44, 1, 0, 0, 31, 25};
  vector<int> win = {31, 10, 45, 1, 6, 19};
  vector<int> result = solution(lottos, win);
  for (int i = 0; i < result.size(); i++)
  {
    cout << result[i] << " ";
  }
  return 0;
}