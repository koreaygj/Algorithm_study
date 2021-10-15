#include <vector>
#include <iostream>
#include <math.h>
using namespace std;

int solution(vector<int> nums)
{
  int answer = 0;
  bool flag = false;
  int num = 0;
  for (int i = 0; i < nums.size(); i++)
  {
    for (int j = i + 1; j < nums.size(); j++)
    {
      for (int k = j + 1; k < nums.size(); k++)
      {
        num = nums[i] + nums[j] + nums[k];
        for (int l = 2; l <= sqrt(num); l++)
        {
          if (num % l == 0)
          {
            flag = false;
            break;
          }
          else
            flag = true;
        }
        if (flag == true)
          answer++;
        flag = false;
      }
    }
  }
  return answer;
}