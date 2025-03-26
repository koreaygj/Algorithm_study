#include <iostream>
using namespace std;
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    string input;
    cin >> input;
    int a, b;
    for (int j = 0; j < input.length(); j++) {
      if (input[j] == ',') {
        a = stoi(input.substr(0, j));
        b = stoi(input.substr(j + 1));
      }
    }
    cout << a + b << "\n";
  }
}