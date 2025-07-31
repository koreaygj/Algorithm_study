#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>

#define fastio cin.tie(0)->ios::sync_with_stdio(0)

using namespace std;

int N;
string operators = " +-";

int evaluate(string expr) {
  string temp = "";
  for (char c : expr) {
    if (c != ' ') temp += c;
  }

  int result = 0;
  int current_num = 0;
  char op = '+';

  for (char c : temp) {
    if (isdigit(c)) {
      current_num = current_num * 10 + (c - '0');
    } else {
      if (op == '+')
        result += current_num;
      else
        result -= current_num;
      current_num = 0;
      op = c;
    }
  }

  if (op == '+')
    result += current_num;
  else
    result -= current_num;

  return result;
}

void dfs(string expr, int index) {
  if (index > N) {
    if (evaluate(expr) == 0) {
      cout << expr << "\n";
    }
    return;
  }

  for (int i = 0; i < 3; i++) {
    string new_expr = expr;
    if (index > 1) {
      new_expr += operators[i];
    }
    new_expr += char('0' + index);
    dfs(new_expr, index + 1);
  }
}

int main() {
  fastio;
  int t;
  cin >> t;

  while (t--) {
    cin >> N;
    dfs("1", 2);
    cout << "\n";
  }

  return 0;
}