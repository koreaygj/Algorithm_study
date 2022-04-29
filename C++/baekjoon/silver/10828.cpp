#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int stack[10001] = {0};
int push(int num)
{
 for (int i = 0; i < 10001; i++)
 {
  if (stack[i] == 0)
  {
   stack[i] = num;
   break;
   return 0;
  }
 }
 return 0;
}
int pop()
{
 for (int i = 10000; i >= 0; i--)
 {
  if (stack[i] != 0)
  {
   cout << stack[i] << "\n";
   stack[i] = 0;
   return 0;
  }
 }
 cout << -1 << "\n";
 return 0;
}
int size()
{
 int count = 0;
 for (int i = 0; i < 10001; i++)
 {
  if (stack[i] != 0)
   count++;
 }
 cout << count << "\n";
 return 0;
}
int empty()
{
 for (int i = 0; i < 10001; i++)
 {
  if (stack[i] != 0)
  {
   cout << 0 << "\n";
   return 0;
  }
 }
 cout << 1 << "\n";
 return 1;
}
int top()
{
 for (int i = 10000; i >= 0; i--)
 {
  if (stack[i] != 0)
  {
   cout << stack[i] << "\n";
   return stack[i];
  }
 }
 cout << -1 << "\n";
 return 0;
}
int main(void)
{
 cin.tie(NULL);
 cout.tie(NULL);
 ios::sync_with_stdio(false);
 int n;
 cin >> n;
 for (int i = 0; i < n; i++)
 {
  string a;
  int num;
  cin >> a;
  if (a == "push")
  {
   cin >> num;
   push(num);
  }
  else if (a == "pop")
   pop();
  else if (a == "size")
   size();
  else if (a == "empty")
   empty();
  else if (a == "top")
   top();
 }
 return 0;
}