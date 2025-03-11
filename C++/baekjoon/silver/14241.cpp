#include <algorithm>
#include <iostream>
using namespace std;
int main() {
  int n;
  cin >> n;
  int x, y;
  int slime = 0;
  int score = 0;
  for (int i = 0; i < n; i++) {
    int tmp;
    cin >> tmp;
    score += slime * tmp;
    slime += tmp;
  }
  cout << score << "\n";
}