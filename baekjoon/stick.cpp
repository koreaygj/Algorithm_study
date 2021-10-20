#include <iostream>
#include <vector>
using namespace std;
int solution(int length)
{
  int answer = 0;
  vector<int> stick = {64};
  int max = 64;
  int size = 0;
  int result = 0;
  int k = 0;
  if (stick[0] > length)
  {
    while (max > length)
    {
      k = stick.back();
      stick.pop_back();
      stick.push_back(k / 2);
      stick.push_back(k / 2);
      for (int i = 0; i < stick.size(); i++)
      {
        size += stick[i];
        max = size;
      }
      size = max - stick.back();
      if (size >= length)
      {
        stick.pop_back();
        if (size == length)
          break;
        max = size;
      }
      size = 0;
    }
  }
  for (int i = 0; i < stick.size(); i++)
  {
    result += stick[i];
    if (result == length)
    {
      answer = i + 1;
      break;
    }
  }
  return answer;
}
int main(void)
{
  int length = 0;
  cin >> length;
  cout << solution(length);
  return 0;
}