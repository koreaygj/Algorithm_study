#include <iostream>
using namespace std;
int main()
{
  int t;
  cin >> t;
  for (int i = 1; i <= t; i++)
  {
    int d, h, m;
    cin >> d >> h >> m;
    if (d <= 11 && h < 11 && m < 11)
    {
      cout << "#" << i << " -1\n";
    }
    else
    {
      int Day = 24 * 60 * ((d - 1) - 11);
      if (Day < 0)
        Day = 0;
      int Hour, Min;
      if (d <= 11)
      {
        if (h < 11)
        {
          cout << "#" << i << " -1\n";
          continue;
        }
        else
        {
          if (h == 11)
          {
            Hour = 0;
            if (m < 11)
            {
              cout << "#" << i << " -1\n";
              continue;
            }
            else
            {
              Min = m - 11;
            }
          }
          else
          {
            Hour = 60 * ((h - 1) - 11);
            Min = 49 + m;
          }
        }
      }
      else
      {
        int defaultH = 12 * 60;
        int defaultM = 49;
        Hour = defaultH;
        Min = defaultM;
        Hour += 60 * h;
        Min += m;
      }
      cout << "#" << i << " " << (Day + Hour + Min) << "\n";
    }
  }
  return 0;
}