#include <algorithm>
#include <iostream>
using namespace std;
int main() {
  int num[3];
  cin >> num[0] >> num[1] >> num[2];
  sort(&num[0], &num[0] + 3);
  cout << num[1] << "\n";
}