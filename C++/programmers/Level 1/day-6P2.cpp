#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int solution(vector<int> d, int budget)
{
  int answer = 0;
  sort(d.begin(), d.end());
  for (int i = 0; i < d.size(); i++)
  {
    budget -= d[i];
    answer = i;
    if (budget <= 0)
    {
      answer = i;
      if (budget == 0)
        answer++;
      break;
    }
  }
  return answer;
}
int main(void)
{
  vector<int> d = {1, 3, 2, 5, 4, 4, 3, 4, 3, 6};
  int budget = 15;
  int result = solution(d, budget);
  cout << result;
  return 0;
}