#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main()
{
  int t;
  cin >> t;
  string input;
  int month, day;
  string s_year, s_month, s_day;
  vector<int> check = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  for (int j = 0; j < t; j++)
  {
    cin >> input;
    s_month = input.substr(4, 2);
    s_day = input.substr(6);
    month = stoi(s_month);
    day = stoi(s_day);
    cout << "#" << j + 1 << " ";
    if (1 <= month && month <= 12 && 1 <= day && day <= check[month - 1])
    {
      cout << input.substr(0, 4) << "/" << s_month << "/" << s_day << endl;
    }
    else
    {
      cout << -1 << endl;
    }
  }
}