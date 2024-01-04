#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(void)
{
 int n;
 long long int answer = 0;
 cin >> n;
 vector<int> num(n, 0);
 for (int i = 0; i < n; i++)
  cin >> num[i];
 sort(num.begin(), num.end());
 if (num.size() % 2 == 0)
  answer = num.front() * num.back();
 else
  answer = num[n / 2] * num[n / 2];
 cout << answer << "\n";
 return 0;
}