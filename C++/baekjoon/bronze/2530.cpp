#include <algorithm>
#include <iostream>
#define fastio cin.tie(0)->ios::sync_with_stdio(0)
using namespace std;
int main() {
  fastio;
  int hour, min, second;
  int tmp = 0;
  cin >> hour >> min >> second >> tmp;
  int h = 3600, m = 60;
  hour += tmp / h;
  tmp %= h;
  min += tmp / m;
  tmp %= m;
  second += tmp;
  if (second >= 60) {
    second %= 60;
    min++;
  }
  if (min >= 60) {
    min %= 60;
    hour++;
  }
  if (hour >= 24) hour %= 24;
  cout << hour << " " << min << " " << second << "\n";
}