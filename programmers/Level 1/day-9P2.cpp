#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> solution(vector<int> arr)
{
  vector<int> answer;
  int count = 0;
  answer.push_back(arr[0]);
  for (int i = 1; i < arr.size(); i++)
  {
    if (answer[count] != arr[i])
    {
      answer.push_back(arr[i]);
      count++;
    }
  }
  return answer;
}
int main(void)
{
  vector<int> arr = {1, 1, 3, 3, 0, 1, 1};
  vector<int> result;
  for (int i = 0; i < solution(arr).size(); i++)
  {
    cout << solution(arr)[i] << " ";
  }
  return 0;
}