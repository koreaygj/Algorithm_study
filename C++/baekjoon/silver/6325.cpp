#include <iostream>
#include <map>
using namespace std;
int main() {
  int cnt = 1;
  while (true) {
    int n;
    cin >> n;
    if (n == 0) break;
    map<string, int> values;
    values.insert({"a", 1});
    for (int i = 0; i < n; i++) {
      string a, b, c;
      cin >> a >> b >> c;
      if (values.find(c) != values.end()) {
        values.insert({a, 1});
      } else {
        values.erase(a);
      }
    }
    cout << "Program #" << cnt++ << "\n";
    if (values.empty())
      cout << "none\n";
    else {
      for (const auto value : values) {
        cout << value.first << " ";
      }
      cout << "\n";
    }
    cout << "\n";
  }
}