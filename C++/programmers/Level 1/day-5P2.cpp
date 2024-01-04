#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
int solution(vector<vector<int>> sizes)
{
  int answer = 0;
  vector<int> width;
  vector<int> length;
  for (int i = 0; i < sizes.size(); i++)
  {
    sort(sizes[i].begin(), sizes[i].end());
    width.push_back(sizes[i][0]);
    length.push_back(sizes[i][1]);
  }
  sort(width.begin(), width.end());
  sort(length.begin(), length.end());
  answer = width.back() * length.back();
  return answer;
}
int main(void)
{
  vector<vector<int>> size = {{60, 50}, {30, 70}, {60, 30}, {80, 40}};
  cout << solution(size);
  return 0;
}