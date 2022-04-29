#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
long long int count(int num)
{
 long long int count = 0;
 while (num >= 5)
 {
  count += num / 5;
  num /= 5;
 }
 return count;
}
long long int count2(int num)
{
 long long int count = 0;
 while (num >= 2)
 {
  count += num / 2;
  num /= 2;
 }
 return count;
}
int main(void)
{
 long long int n, k;
 cin >> n >> k;
 long long int answer = 0;
 long long int answer2 = 0;
 answer = count(n);
 answer -= count(k);
 answer -= count(n - k);
 answer2 = count2(n);
 answer2 -= count2(k);
 answer2 -= count2(n - k);
 answer = answer < answer2 ? answer : answer2;
 cout << answer << "\n";
 return 0;
}