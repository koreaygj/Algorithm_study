#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands)
{
  vector<int> answer;
  for (int i = 0; i < commands.size(); i++)
  {
    vector<int> sorted(commands[i][1] - commands[i][0] + 1);
    int k = 0;
    for (int j = commands[i][0] - 1; j < commands[i][1]; j++)
    {
      cout << array[j] << " ";
      sorted[k] = array[j];
      k++;
    }
    sort(sorted.begin(), sorted.end());
    answer.push_back(sorted[commands[i][2] - 1]);
  }
  return answer;
}
int main(void)
{
  vector<int> array = {1, 5, 2, 6, 3, 7, 4};
  vector<vector<int>> commands = {{2, 5, 3}, {4, 4, 1}, {1, 6, 3}};
  solution(array, commands);
  // for (int i = 0; i < solution(array, commands).size(); i++)
  //   cout << solution(array, commands)[i] << " ";
}