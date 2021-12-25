#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
int main(void)
{
 string s;
 cin >> s;
 vector<int> num;
 vector<int> sign;
 string n;
 bool flag = true;
 int answer = 0;
 for (int i = 0; i < s.size(); i++)
 {
  if (s[i] >= '0' && s[i] <= '9')
  {
   n += s[i];
  }
  else
  {
   if (flag == false)
    answer -= stoi(n);
   else
    answer += stoi(n);
   if (s[i] == '-')
    flag = false;
   n = "";
  }
 }
 if (flag == false)
  answer -= stoi(n);
 else
  answer += stoi(n);
 cout << answer << "\n";
 return 0;
}