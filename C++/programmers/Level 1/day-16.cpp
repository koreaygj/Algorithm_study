#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
vector<int> solution(int N, vector<int> stages)
{
  vector<double> answer(N);
  vector<int> index;
  vector<double> user(N);
  vector<double> per(N);
  bool flag = false;
  for (int i = 0; i < stages.size(); i++)
  {
    if (stages[i] <= N)
      answer[stages[i] - 1]++;
  }
  for (int i = 0; i < stages.size(); i++)
  {
    if (stages[i] > N)
      stages[i] = N;
    for (int j = 0; j < stages[i]; j++)
      user[j]++;
  }
  for (int i = 0; i < N; i++)
  {
    if (user[i] != 0)
      per[i] = answer[i] / user[i];
  }
  for (int i = 0; i < N; i++)
  {
    double max = *max_element(per.begin(), per.end());
    for (int j = 0; j < N; j++)
    {
      if (per[j] == max)
      {
        index.push_back(j + 1);
        per[j] = -1;
        break;
      }
    }
  }
  return index;
}
int main(void)
{
  int n = 5;
  vector<int> stages = {2, 1, 2, 6, 2, 4, 3, 3};
  for (int i = 0; i < n; i++)
  {
    cout << solution(n, stages)[i] << " ";
  }
  return 0;
}