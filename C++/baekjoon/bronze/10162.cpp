#include <iostream>
using namespace std;
int main() {
  int time[3] = {300, 60, 10};
  int t;
  cin >> t;
  if (t % 10 != 0) {
    cout << "-1\n";
    return 0;
  }
  for (int i = 0; i < 3; i++) {
    if (t >= time[i])
      cout << t / time[i] << " ";
    else
      cout << 0 << " ";
    t %= time[i];
  }
  cout << "\n";
}