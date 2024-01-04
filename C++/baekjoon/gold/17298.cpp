#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(void)
{
 cin.tie(NULL);
 cout.tie(NULL);
 ios::sync_with_stdio(false);
 int n;
 cin >> n;
 vector<int> array(n, 0);
 vector<int> stack;
 vector<int> answer(n, 0);
 for (int i = 0; i < n; i++)
  cin >> array[i];
 answer[n - 1] = -1;
 for (int i = n - 1; i >= 0; i--)
 {
  bool flag = true;
  while (!stack.empty())
  {
   if (stack.back() > array[i])
   {
    flag = false;
    answer[i] = stack.back();
    break;
   }
   stack.pop_back();
  }
  if (flag == true)
   answer[i] = -1;
  stack.push_back(array[i]);
 }
 for (int j = 0; j < n; j++)
  cout << answer[j] << " ";
 cout << endl;
 return 0;
}