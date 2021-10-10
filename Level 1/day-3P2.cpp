#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
vector<int> solution(vector<int> numbers)
{
  vector<int> answer;
  vector<int> number;
  int k = 0;
  for (int j = 0; j < numbers.size() - 1; j++)
  {
    k = j + 1;
    for (k; k < numbers.size(); k++)
    {
      number.push_back(numbers[j] + numbers[k]);
    }
  }
  sort(number.begin(), number.end());
  answer.push_back(number.front());
  int q = 0;
  for (int i = 0; i < number.size(); i++)
  {
    if (number[i] != answer[q])
    {
      answer.push_back(number[i]);
      q++;
    }
  }
  return answer;
}
int main(void)
{
  vector<int> numbers = {2, 1, 3, 4, 1};
  vector<int> result = solution(numbers);
  for (int i = 0; i < result.size(); i++)
    cout << result[i] << " ";
  return 0;
}