#include <algorithm>
#include <iostream>
#include <vector>
#define fastio cin.tie(0)->ios::sync_with_stdio(0)
using namespace std;
class BigInt {
 private:
  string number;

 public:
  BigInt(string number = "");
  void Show() const;
  BigInt operator+(const BigInt& num);
  BigInt operator*(const BigInt& num);
};
BigInt::BigInt(string n) { this->number = n; }
void BigInt::Show() const { cout << this->number << "\n"; }
BigInt BigInt::operator+(const BigInt& num) {
  string n1 = this->number;
  string n2 = num.number;
  if (n1.size() > n2.size()) {
    for (int i = 0; i < n1.size() - n2.size(); i++) n2 = "0" + n2;
  } else {
    for (int i = 0; i < n2.size() - n1.size(); i++) n1 = "0" + n1;
  }
  string result = "";
  int up = 0;
  for (int i = n1.size() - 1; i >= 0; i--) {
    int digit = (n1[i] - '0') + (n2[i] - '0') + up;
    if (digit >= 10) {
      up = digit / 10;
      digit = digit % 10;
    } else {
      up = 0;
    }
    result = to_string(digit) + result;
  }
  if (up == 1) {
    result = "1" + result;
  }
  return BigInt(result);
}
BigInt BigInt::operator*(const BigInt& num) {
  if (this->number == "0" || num.number == "0") {
    return BigInt("0");
  }

  string n1 = this->number;
  string n2 = num.number;

  int len = n1.size() + n2.size();
  vector<int> result(len, 0);

  for (int i = n1.size() - 1; i >= 0; i--) {
    for (int j = n2.size() - 1; j >= 0; j--) {
      int product = (n1[i] - '0') * (n2[j] - '0');

      int pos1 = i + j;
      int pos2 = i + j + 1;

      int sum = product + result[pos2];

      result[pos1] += sum / 10;
      result[pos2] = sum % 10;
    }
  }

  string resultStr = "";
  int i = 0;

  while (i < len - 1 && result[i] == 0) {
    i++;
  }
  while (i < len) {
    resultStr += to_string(result[i]);
    i++;
  }
  return BigInt(resultStr);
}

int main() {
  int n;
  BigInt dp[1001], dp_doubleO[1001];
  dp[0] = BigInt("1");
  dp[1] = BigInt("1");
  dp_doubleO[0] = BigInt("0");
  dp_doubleO[1] = BigInt("0");
  BigInt two("2");
  for (int i = 2; i <= 1000; i++) {
    dp[i] = dp[i - 1] * two;
  }
  for (int i = 2; i <= 1000; i++) {
    dp_doubleO[i] = dp_doubleO[i - 2] + dp[i - 2];
  }
  while (cin >> n) {
    if (n < 2)
      cout << "0\n";
    else {
      dp_doubleO[n].Show();
    }
  }
}