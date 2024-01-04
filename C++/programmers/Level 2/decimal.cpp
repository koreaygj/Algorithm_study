#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n;
vector<bool> check(8, 0);
vector<int> ans;
string case_num = "";
string input;
bool check_decimal(int n)
{
 if (n == 0 || n == 1)
  return false;
 for (int i = 2; i * i <= n; i++)
 {
  if (n % i == 0)
   return false;
 }
 return true;
}
void permutation(int count)
{
 if (count == n)
  return;
 for (int i = 0; i < n; i++)
 {
  if (check[i] == true)
   continue;
  case_num += input[i];
  ans.push_back(stoi(case_num));
  check[i] = true;
  permutation(count + 1);
  check[i] = false;
  case_num.pop_back();
 }
}
int solution(string numbers)
{
 int answer = 0;
 n = numbers.size();
 input = numbers;
 permutation(0);
 sort(ans.begin(), ans.end());
 ans.erase(unique(ans.begin(), ans.end()), ans.end());
 for (int i = 0; i < ans.size(); i++)
 {
  if (check_decimal(ans[i]))
   answer++;
 }
 return answer;
}
int main(void)
{
 string str = "17";
 cout << solution(str);
 return 0;
}