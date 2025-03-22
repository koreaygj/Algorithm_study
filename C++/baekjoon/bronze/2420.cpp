#include <iostream>
using namespace std;
int main() {
  long long int n, m;
  cin >> n >> m;
  long long int sub = n > m ? n - m : m - n;
  cout << sub << "\n";
}