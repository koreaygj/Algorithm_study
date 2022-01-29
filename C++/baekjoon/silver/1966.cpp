#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
int solution(int n, int index)
{
 vector<int> que(n, 0);
 vector<int> priority;
 int answer = 0;
 int count = 0;
 for (int i = 0; i < n; i++)
  cin >> que[i];
 priority = que;
 sort(priority.begin(), priority.end());
 while (1)
 {
  if (que[count] < priority.back())
  {
   que.push_back(que[count]);
   if (index == count)
    index = que.size() - 1;
  }
  else if (que[count] == priority.back())
  {
   answer++;
   que[count] = 0;
   priority.pop_back();
   if (index == count)
    break;
  }
  count++;
 }
 return answer;
}
int main(void)
{
 int t;
 cin >> t;
 for (int i = 0; i < t; i++)
 {
  int n, index;
  cin >> n >> index;
  cout << solution(n, index) << "\n";
 }
 return 0;
}