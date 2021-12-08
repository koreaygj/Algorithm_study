#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> drink(10001, 0);
int solution(int n, int a)
{
 int answer = 0;
 int a = 0;
 int index = 0;
 for (int i = 0; i < a; i++)
 {
  switch (index)
  {
  case 0:
  case 1:
  case 2:
  }
 }
 return answer;
}
int main(void)
{
 int n, ans = 0;
 cin >> n;
 int a = n / 3;
 for (int i = 0; i < n; i++)
 {
  cin >> drink[i];
  ans += drink[i];
 }
 if (n == 1)
  cout << drink[0] << "\n";
 if (n == 2)
  cout << drink[0] + drink[1] << "\n";
 if (n >= 3)
  cout << solution(n, a) << "\n";
 return 0;
}