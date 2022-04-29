#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int main(void)
{
 queue<int> que;
 int n;
 cin >> n;
 for (int i = 0; i < n; i++)
 {
  string cmd;
  int num;
  cin >> cmd;
  if (cmd == "push")
  {
   cin >> num;
   que.push(num);
  }
  else if (cmd == "pop")
  {
   if (que.empty())
    cout << "-1\n";
   else
   {
    cout << que.front() << "\n";
    que.pop();
   }
  }
  else if (cmd == "size")
  {
   cout << que.size() << "\n";
  }
  else if (cmd == "empty")
  {
   if (que.empty())
    cout << "1\n";
   else
    cout << "0\n";
  }
  else if (cmd == "front")
  {
   if (que.empty())
    cout << "-1\n";
   else
    cout << que.front() << "\n";
  }
  else
  {
   if (que.empty())
    cout << "-1\n";
   else
    cout << que.back() << "\n";
  }
 }
 return 0;
}