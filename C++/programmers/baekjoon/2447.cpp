#include <iostream>
#include <vector>
#include <string>
#include <math.h>
using namespace std;
vector<vector<string>> solution(int n)
{
  vector<vector<string>> answer;
  int size = pow(3, n);
  if (n == 1)
  {
    answer.push_back({"*", "*", "*"});
    answer.push_back({"*", " ", "*"});
    answer.push_back({"*", "*", "*"});
    return answer;
  }
  else if (n > 1)
  {
    vector<vector<string>> previous = solution(n - 1);
    answer = previous;
    for (int i = 0; i < previous.size(); i++)
    {
      for (int j = 0; j < 2; j++)
        answer[i].insert(answer[i].end(), previous[i].begin(), previous[i].end());
    }
    vector<vector<string>> copy = answer;
    for (int i = 0; i < 2; i++)
      answer.insert(answer.end(), copy.begin(), copy.end());
    for (int i = size / 3; i < size / 3 * 2; i++)
      for (int j = size / 3; j < size / 3 * 2; j++)
        answer[i][j] = " ";
  }
  return answer;
}
int main(void)
{
  int n = 0, a = 0;
  vector<vector<string>> ans;
  cin >> n;
  while (n != 1)
  {
    n /= 3;
    a++;
  }
  ans = solution(a);
  for (int i = 0; i < ans.size(); i++)
  {
    for (int j = 0; j < ans.size(); j++)
      cout << ans[i][j];
    cout << endl;
  }
  return 0;
}
