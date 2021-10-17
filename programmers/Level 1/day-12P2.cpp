#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int solution(vector<int> nums)
{
  int answer = 0;
  sort(nums.begin(), nums.end());
  for (int i = 0; i < nums.size(); i++)
  {
    if (nums[i] != nums[i + 1])
    {
      answer++;
    }
    if (answer == nums.size() / 2)
      break;
    cout << answer << " ";
  }
  return answer;
}
int main(void)
{
  vector<int> nums = {3, 3, 3, 2, 2, 2};
  cout << solution(nums);
  return 0;
}