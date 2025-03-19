#include <iostream>
using namespace std;
int main() {
  int arr[8] = {1, 2, 3, 4, 5, 6, 7, 8};
  bool is_inc = true, is_dec = true;
  for (int i = 0; i < 8; i++) {
    int tmp;
    cin >> tmp;
    if (tmp != arr[i]) is_inc = false;
    if (tmp != arr[7 - i]) is_dec = false;
    if (!is_inc && !is_dec) {
      break;
    }
  }
  if (is_inc)
    cout << "ascending\n";
  else if (is_dec)
    cout << "descending\n";
  else
    cout << "mixed\n";
}