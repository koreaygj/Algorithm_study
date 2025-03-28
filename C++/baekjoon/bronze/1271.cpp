#include <iostream>
#include <string>
#define fastio cin.tie(0)->ios::sync_with_stdio(0);
using namespace std;

string Division;
string Remainder;

void removeLeadingZeros(string &s) {
  int i = 0;
  while (i < s.size() - 1 && s[i] == '0') i++;
  if (i > 0) s = s.substr(i);
}

bool isSmaller(const string &n, const string &m) {
  if (n.size() != m.size()) return n.size() < m.size();

  for (size_t i = 0; i < n.size(); i++) {
    if (n[i] != m[i]) return n[i] < m[i];
  }
  return false;
}

string subtract(string n, string m) {
  string result = "";
  int n_len = n.size();
  int m_len = m.size();
  int diff = n_len - m_len;

  int carry = 0;

  for (int i = m_len - 1; i >= 0; i--) {
    int sub = (n[i + diff] - '0') - (m[i] - '0') - carry;

    if (sub < 0) {
      sub += 10;
      carry = 1;
    } else {
      carry = 0;
    }

    result = char(sub + '0') + result;
  }

  for (int i = diff - 1; i >= 0; i--) {
    int sub = (n[i] - '0') - carry;

    if (sub < 0) {
      sub += 10;
      carry = 1;
    } else {
      carry = 0;
    }

    result = char(sub + '0') + result;
  }

  removeLeadingZeros(result);
  return result;
}

void longDivision(const string &n, const string &m) {
  if (isSmaller(n, m)) {
    Division = "0";
    Remainder = n;
    return;
  }

  string current = "";
  Division = "";

  for (int i = 0; i < n.size(); i++) {
    current += n[i];
    removeLeadingZeros(current);

    int quotientDigit = 0;
    string temp = current;

    while (!isSmaller(temp, m)) {
      temp = subtract(temp, m);
      quotientDigit++;
    }

    Division += char('0' + quotientDigit);
    current = temp;
  }

  removeLeadingZeros(Division);
  Remainder = current;
}

int main() {
  fastio;
  string n, m;
  cin >> n >> m;

  longDivision(n, m);

  cout << Division << "\n";
  cout << Remainder << "\n";

  return 0;
}