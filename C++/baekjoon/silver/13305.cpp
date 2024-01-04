#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(void)
{
 int n;
 long long int min = 0;
 cin >> n;
 vector<long long int> length(n - 1, 0);
 vector<long long int> city(n, 0);
 long long int answer = 0;
 for (int i = 0; i < n - 1; i++)
  cin >> length[i];
 for (int i = 0; i < n; i++)
  cin >> city[i];
 min = city[0];
 for (int i = 0; i < n - 1; i++)
 {
  if (city[i] < min)
   min = city[i];
  answer += min * length[i];
 }
 cout << answer << "\n";
 return 0;
}