#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(void)
{
 int n;
 cin >> n;
 vector<int> stack(100001, 0);
 string answer = "";
 int index = 1;
 for (int i = 0; i < n; i++)
 {
  int num;
  cin >> num;
  if (answer == "NO")
   continue;
  for (int j = index; j <= num; j++)
  {
   if (stack[j] == 0)
   {
    index++;
    stack[j] = 1;
    answer += "+";
   }
  }
  for (int j = index; j >= 1; j--)
  {
   if (stack[j] == 1)
   {
    stack[j] = 0;
    answer += "-";
    if (j == num)
     break;
   }
   else if (j == num)
   {
    answer = "NO";
    break;
   }
  }
 }
 if (answer == "NO")
 {
  cout << "NO\n";
  return 0;
 }
 for (int i = 0; i < answer.size(); i++)
  cout << answer[i] << "\n";
 return 0;
}