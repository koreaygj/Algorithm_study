#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2)
{
  int size = arr1.size();
  cout << size << arr1[0].size() << endl;
  vector<vector<int>> answer(size, vector<int>(arr1[0].size(), 0));
  vector<int> mid;
  for (int i = 0; i < size; i++)
  {
    for (int j = 0; j < arr1[i].size(); j++)
    {
      answer[i][j] = arr1[i][j] + arr2[i][j];
    }
  }
  return answer;
}
int main(void)
{
  vector<vector<int>> arr1 = {{1}, {2}};
  vector<vector<int>> arr2 = {{3}, {4}};
  int size = solution(arr1, arr2).size();
  for (int i = 0; i < size; i++)
    for (int j = 0; j < size; j++)
      cout << solution(arr1, arr2)[i][j] << " ";
  return 0;
}