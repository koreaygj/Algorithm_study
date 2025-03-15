#include <iostream>
#include <vector>
using namespace std;
int main() {
  vector<string> lines;
  string line;
  while (getline(cin, line)) {
    lines.push_back(line);
  }
  for (const auto& line : lines) cout << line << "\n";
}