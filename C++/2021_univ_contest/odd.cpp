#include <iostream>
using namespace std;
int main()
{
  int t, n;
  cin >> t;
  for (int i = 1; i <= t; i++)
  {
    int sum = 0;
    for (int j = 0; j < 10; j++)
    {
      cin >> n;
      if (n % 2 == 1)
        sum += n;
    }
    cout << "#" << i << " " << sum << endl;
  }
}