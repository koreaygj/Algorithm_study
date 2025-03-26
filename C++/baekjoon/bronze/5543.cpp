#include <iostream>
using namespace std;
int main() {
  int min_ham = 10000;
  int min_drink = 10000;
  int tmp;
  for (int i = 0; i < 3; i++) {
    cin >> tmp;
    min_ham = tmp < min_ham ? tmp : min_ham;
  }
  for (int i = 0; i < 2; i++) {
    cin >> tmp;
    min_drink = tmp < min_drink ? tmp : min_drink;
  }
  cout << min_ham + min_drink - 50 << "\n";
}