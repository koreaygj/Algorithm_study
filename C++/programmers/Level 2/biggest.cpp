#include <string>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
bool cmp(string a, string b)
{
 if (a + b > b + a)
  return true;
 else
  return false;
}

string solution(vector<int> numbers)
{
 string answer = "";
 vector<string> substr;
 for (int i = 0; i < numbers.size(); i++)
 {
  substr.push_back(to_string(numbers.at(i)));
 }
 sort(substr.begin(), substr.end(), cmp);
 for (string str : substr)
 {
  answer += str;
 }
 if (answer[0] == '0')
  return "0";
 return answer;
}