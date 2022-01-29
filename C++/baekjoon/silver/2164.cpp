#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
int main(void)
{
 int n;
 cin >> n;
 queue<int> que;
 for (int i = 1; i <= n; i++)
  que.push(i);
 while (1)
 {
  if (que.size() == 1)
   break;
  que.pop();
  que.push(que.front());
  que.pop();
 }
 cout << que.front() << "\n";
 return 0;
}