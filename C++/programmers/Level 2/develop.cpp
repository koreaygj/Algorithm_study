#include <string>
#include <vector>
#include <iostream>
using namespace std;
vector<int> solution(vector<int> progresses, vector<int> speeds)
{
 vector<int> answer;
 vector<int> date(progresses.size(), 0);
 int count = 0;
 while (1)
 {
  count++;
  bool flag = true;
  for (int i = 0; i < progresses.size(); i++)
  {
   progresses[i] += speeds[i];
   if (progresses[i] >= 100)
   {
    if (date[i] == 0)
    {
     date[i] = count;
    }
   }
   else
    flag = false;
  }
  if (flag == true)
   break;
 }
 for (int i = 0; i < date.size(); i++)
 {
  if (date[i] == 0)
   continue;
  int count = 1;
  for (int j = i + 1; j < date.size(); j++)
  {
   if (date[j] == 0)
    continue;
   if (date[i] >= date[j])
   {
    count++;
    date[j] = 0;
   }
   else
    break;
  }
  answer.push_back(count);
 }
 return answer;
}
int main(void)
{
 vector<int> input1 = {93, 30, 55};
 vector<int> input2 = {1, 30, 5};
 vector<int> answer = solution(input1, input2);
 for (int answer : answer)
  cout << answer << " ";
 return 0;
}