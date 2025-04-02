#include <algorithm>
#include <iostream>
#include <map>
using namespace std;
int main() {
  int n;
  cin >> n;
  map<string, int> log;
  for (int i = 0; i < n; i++) {
    string a, b;
    cin >> a >> b;
    if (b == "enter")
      log.insert({a, 1});
    else
      log.erase(a);
  }
  for (auto it = log.rbegin(); it != log.rend(); ++it) {
    cout << it->first << "\n";
  }
}