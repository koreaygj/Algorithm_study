#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class line
{
public:
 int a;
 int b;
};
bool comp(line x, line y)
{
 return x.a < y.a;
}
int main(void)
{
 vector<line> input;
 int answer = 0;
 int n, a, b;
 cin >> n;
 input.push_back({0, 0});
 for (int i = 1; i <= n; i++)
 {
  cin >> a >> b;
  input.push_back({a, b});
 }
 vector<int> dp(501, 0);
 sort(input.begin(), input.end(), comp);
 for (int i = 1; i <= n; i++)
 {
  for (int j = 0; j < i; j++)
  {
   if (input[i].b > input[j].b)
   {
    if (dp[j] >= dp[i])
     dp[i] = dp[j] + 1;
   }
  }
  answer = max(answer, dp[i]);
 }
 cout << n - answer << "\n";
 return 0;
}