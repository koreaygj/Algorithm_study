#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
  int t;
  cin >> t;
  int a[100];
  int n, k;
  int mid, fin, hom;
  char grades[10][3] = {"A+", "A0", "A-", "B+", "B0", "B-", "C+", "C0", "C-", "D0"};
  for (int i = 1; i <= t; i++)
  {
    cin >> n >> k;
    for (int j = 0; j < n; j++)
    {
      cin >> mid >> fin >> hom;
      a[j] = mid * 35 + fin * 45 + hom * 20;
    }
    int k_score = a[k - 1];
    int k_rank;
    sort(a, a + n);
    for (int j = 0; j < n; j++)
    {
      if (a[j] == k_score)
      {
        k_rank = n - 1 - j;
        break;
      }
    }
    cout << "#" << i << " " << grades[10 * k_rank / n];
  }
}