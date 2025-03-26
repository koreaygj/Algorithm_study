#include <iostream>
using namespace std;
int main() {
  int angle[3];
  cin >> angle[0] >> angle[1] >> angle[2];
  if (angle[0] + angle[1] + angle[2] == 180) {
    if (angle[0] == 60 && angle[1] == 60 && angle[2] == 60)
      cout << "Equilateral\n";
    else if (angle[0] == angle[1] || angle[1] == angle[2] ||
             angle[0] == angle[2]) {
      cout << "Isosceles\n";
    } else {
      cout << "Scalene\n";
    }
  } else {
    cout << "Error\n";
  }
}