#include <iostream>
using namespace std;
string Memo[10001];
string sum(string a, string b) {
  string ans = "";
  if (a.length() < b.length()) {
    string tmp = a;
    a = b;
    b = tmp;
  }
  int carry = 0;
  for (int i = 0; i < b.length(); i++) {
    int digit_a = a[a.length() - 1 - i] - '0';
    int digit_b = b[b.length() - 1 - i] - '0';
    int sum = digit_a + digit_b + carry;
    carry = sum / 10;
    ans = to_string(sum % 10) + ans;
  }
  for (int i = b.length(); i < a.length(); i++) {
    int digit_a = a[a.length() - 1 - i] - '0';
    int sum = digit_a + carry;
    carry = sum / 10;
    ans = to_string(sum % 10) + ans;
  }
  if (carry > 0) {
    ans = to_string(carry) + ans;
  }
  return ans;
}
string findMatch(string n) {
  int i_n = stoi(n);
  if (i_n == 0) return "2";
  if (i_n == 1) return "1";
  if (Memo[i_n].length() != 0) return Memo[i_n];
  return Memo[i_n] =
             sum(findMatch(to_string(i_n - 1)), findMatch(to_string(i_n - 2)));
}

int main() {
  string n;
  for (int i = 0; i <= 10000; i++) {
    Memo[i] = "";
  }
  while (cin >> n) {
    cout << findMatch(n) << "\n";
  }
}