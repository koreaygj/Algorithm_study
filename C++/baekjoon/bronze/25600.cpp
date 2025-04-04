#include <iostream>
using namespace std;
int main() {
  int n;
  cin >> n;
  int max_score = 0;
  for (int i = 0; i < n; i++) {
    int a, d, g;
    cin >> a >> d >> g;
    bool is_double = false;
    is_double = a == d + g ? true : false;
    int tmp = 0;
    if (is_double)
      tmp = a * (d + g) * 2;
    else
      tmp = a * (d + g);
    max_score = max_score >= tmp ? max_score : tmp;
  }
  cout << max_score << "\n";
}