#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(void)
{
 int n;
 cin >> n;
 int answer = 0;
 while (n >= 5)
 {
  answer += n / 5;
  n /= 5;
 }
 cout << answer << "\n";
 return 0;
}