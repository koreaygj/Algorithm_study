#include <string>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> solution(vector<int> arr)
{
  vector<int> answer(arr.size() - 1, 0);
  if (arr.size() == 1)
  {
    answer.push_back(-1);
    return answer;
  }
  arr.erase(min_element(arr.begin(), arr.end()));
  return arr;
}