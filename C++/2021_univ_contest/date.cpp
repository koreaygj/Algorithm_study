#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
string check(int a)
{
  string answer;
  if (1 <= a && a <= 12)
  {
    answer = "MM";
  }
  else
    answer = "YY";
  return answer;
}
int main(void)
{
  int t;
  cin >> t;
  for (int i = 0; i < t; i++)
  {
    string s, ans1, ans2;
    string answer;
    cin >> s;
    ans1 = check(stoi(s.substr(0, 2)));
    ans2 = check(stoi(s.substr(2, 2)));
    if (ans1 == "MM" && ans2 == "MM")
      answer = "AMBIGUOUS";
    else if (ans1 == "YY" && ans2 == "YY")
      answer = "NA";
    else
      answer = ans1 + ans2;
    cout << "#" << i + 1 << " " << answer << endl;
  }
}
