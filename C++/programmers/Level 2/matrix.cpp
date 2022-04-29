#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2)
{
 vector<vector<int>> answer(arr1.size(), vector<int>(arr2[0].size(), 0));
 for (int i = 0; i < answer.size(); i++)
 {
  for (int j = 0; j < answer[i].size(); j++)
  {
   for (int k = 0; k < arr1[0].size(); k++)
   {
    answer[i][j] += arr1[i][k] * arr2[k][j];
   }
  }
 }
 return answer;
}
int main(void)
{
 vector<vector<int>> input1 = {{1, 4}, {3, 2}, {4, 1}};
 vector<vector<int>> input2 = {{3, 3}, {3, 3}};
 vector<vector<int>> answer = solution(input1, input2);
 for (int i = 0; i < answer.size(); i++)
 {
  for (int j = 0; j < answer[0].size(); j++)
   cout << answer[i][j] << " ";
  cout << endl;
 }
 return 0;
}