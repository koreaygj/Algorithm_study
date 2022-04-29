#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(void)
{
 int n;
 int answer = 0;
 int answer2 = 0;
 cin >> n;
 vector<int> time(1001, 0);
 for (int i = 1; i <= n; i++)
 {
  cin >> time[i];
 }
 // for (int i = 1; i <= n; i++)
 // {
 //  time[i] += time[i - 1];
 //  answer += time[i];
 // }
 sort(time.begin() + 1, time.begin() + 1 + n);
 for (int i = 1; i <= n; i++)
 {
  time[i] += time[i - 1];
  answer2 += time[i];
 }
 cout << answer << "\n";
 cout << answer2 << "\n";
 return 0;
}