#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
long long int solution(int n)
{
 vector<vector<long long int>> num(101, vector<long long int>(10, 1));
 long long int answer = 0;
 num[0][0] = 0;
 for (int i = 0; i < n - 1; i++)
 {
  for (int j = 0; j < 10; j++)
  {
   if (j == 0)
    num[i + 1][j] = num[i][j + 1] % 1000000000;
   else if (j == 9)
    num[i + 1][j] = num[i][j - 1] % 1000000000;
   else
    num[i + 1][j] = (num[i][j - 1] + num[i][j + 1]) % 1000000000;
  }
 }
 for (int i = 0; i < 10; i++)
 {
  answer += num[n - 1][i] % 1000000000;
 }
 return answer;
}
int main(void)
{
 int n;
 cin >> n;
 cout << solution(n) % 1000000000 << "\n";
 return 0;
}