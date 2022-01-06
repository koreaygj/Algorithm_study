#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int gcf(int a, int b)
{
 if (b == 0)
  return a;
 return gcf(b, a % b);
}
int main(void)
{
 int n;
 cin >> n;
 vector<long long int> m(n, 0);
 vector<int> answer;
 for (int i = 0; i < n; i++)
  cin >> m[i];
 sort(m.begin(), m.end());
 int num;
 num = m[1] - m[0];
 for (int i = 2; i < n; i++)
 {
  if (num < m[i] - m[i - 1])
   num = gcf(m[i] - m[i - 1], num);
  else
   num = gcf(num, m[i] - m[i - 1]);
 }
 for (int i = 2; i * i <= num; i++)
 {
  if (num % i == 0)
  {
   if (num / i != i)
    answer.push_back(num / i);
   answer.push_back(i);
  }
 }
 answer.push_back(num);
 sort(answer.begin(), answer.end());
 for (int answer : answer)
  cout << answer << " ";
 return 0;
}