#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(vector<int> priorities, int location)
{
  int answer = 0;
  int i = 0;
  vector<int> que;
  bool flag = true;
  while (i < priorities.size())
  {
    for (int j = i + 1; j < priorities.size(); j++)
    {
      if (priorities[i] < priorities[j])
      {
        priorities.push_back(priorities[i]);
        if (i == location)
          location = priorities.size() - 1;
        // cout << location << endl;
        flag = true;
        break;
      }
      else
        flag = false;
    }
    if (flag == false)
    {
      que.push_back(priorities[i]);
      if (i == location)
      {
        answer = que.size();
        break;
      }
    }
    // for (int k = 0; k < priorities.size(); k++)
    //   cout << priorities[k] << " ";
    // cout << endl;
    i++;
  }
  return answer;
}
int main(void)
{
  vector<int> a = {2, 3, 3, 2, 9, 3, 3};
  int i = 3;
  cout << solution(a, i);
  return 0;
}