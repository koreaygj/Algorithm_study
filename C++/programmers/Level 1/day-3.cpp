#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> answers)
{
  vector<int> answer;
  vector<int> num1 = {1, 2, 3, 4, 5};
  vector<int> num2 = {2, 1, 2, 3, 2, 4, 2, 5};
  vector<int> num3 = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};
  int score1 = 0;
  int score2 = 0;
  int score3 = 0;
  int j = 0;
  int k = 0;
  int q = 0;
  for (int i = 0; i < answers.size(); i++)
  {
    if (j == num1.size())
      j = 0;
    if (k == num2.size())
      k = 0;
    if (q == num3.size())
      q = 0;
    if (num1[j] == answers[i])
      score1++;
    if (num2[k] == answers[i])
      score2++;
    if (num3[q] == answers[i])
      score3++;
    j++;
    k++;
    q++;
  }
  if (score1 >= score2)
  {
    if (score1 >= score3)
    {
      answer.push_back(1);
      if (score1 == score2)
        answer.push_back(2);
      if (score1 == score3)
        answer.push_back(3);
    }
    else
      answer.push_back(3);
  }
  else
  {
    if (score2 >= score3)
    {
      answer.push_back(2);
      if (score2 == score3)
        answer.push_back(3);
    }
    else
      answer.push_back(3);
  }
  sort(answer.begin(), answer.end());
  return answer;
}
int main(void)
{
  vector<int> answers = {2, 1, 2, 3, 2, 4};
  vector<int> result = solution(answers);
  for (int i = 0; i < result.size(); i++)
    cout << result[i] << " ";
  return 0;
}