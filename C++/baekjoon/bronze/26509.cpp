#include <iostream>
#include <vector>
using namespace std;
bool checkRight(vector<int> a) {
  return a[2] * a[2] == a[0] * a[0] + a[1] * a[1];
}
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    bool check = false;
    vector<int> a(3, 0);
    vector<int> b(3, 0);
    cin >> a[0] >> a[1] >> a[2];
    cin >> b[0] >> b[1] >> b[2];
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    if (a[2] == b[2] && a[1] == b[1] && a[0] == b[0]) {
      if (checkRight(a) && checkRight(b)) check = true;
    }
    if (check)
      cout << "YES\n";
    else
      cout << "NO\n";
  }
}