
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t, n;
  int score;
  vector<int> scores(101, 0);
  vector<int> reset(101, 0);
  cin >> t;
  for (int i = 1; i <= t; i++)
  {
    cin >> n;
    for (int j = 0; j < 1000; j++)
    {
      cin >> score;
      scores[score]++;
    }
    for (int j = 100; j >= 0; j--)
    {
      if (scores[j] == *max_element(scores.begin(), scores.end()))
      {
        cout << "#" << n << " " << j << "\n";
        break;
      }
    }
    scores = reset;
  }
  return 0;
}