#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
int main(void)
{
 int n, k;
 cin >> n >> k;
 int count = 1;
 queue<int> table;
 vector<int> answer;
 for (int i = 1; i <= n; i++)
  table.push(i);
 while (answer.size() != n)
 {
  if (count % k == 0)
   answer.push_back(table.front());
  else
   table.push(table.front());
  table.pop();
  count++;
 }
 cout << "<";
 for (int i = 0; i < n - 1; i++)
  cout << answer[i] << ", ";
 cout << answer.back() << ">";
 return 0;
}