#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int solution(vector<int> numbers)
{
  int answer = 45;
  int result = 0;
  bool get = false;
  vector<int> compare = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  sort(numbers.begin(), numbers.end());
  for (int i = 0; i < numbers.size(); i++)
  {
    for (int j = 0; j <= 9; j++)
    {
      if (numbers[i] == compare[j])
      {
        answer -= compare[j];
        break;
      }
    }
  }
  return answer;
}
int main(void)
{
  vector<int> numbers = {1, 2, 3, 4, 6, 7, 8, 0};
  cout << solution(numbers);
}