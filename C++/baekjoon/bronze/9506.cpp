#include <iostream>
#include <vector>
using namespace std;
bool findMeasure(int n) {
  int tmp = 0;
  vector<int> measures;
  for (int i = 1; i < n; i++) {
    if (n % i == 0) {
      tmp += i;
      measures.push_back(i);
    }
  }
  if (tmp == n) {
    printf("%d = ", n);
    for (int i = 0; i < measures.size() - 1; i++) {
      cout << measures[i] << " + ";
    }
    cout << measures[measures.size() - 1] << "\n";
  } else {
    printf("%d is NOT perfect.\n", n);
  }
  return tmp == n;
}
int main() {
  int n;
  while (cin >> n) {
    if (n == -1) break;
    findMeasure(n);
  }
}