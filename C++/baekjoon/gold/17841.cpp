#include <cstring>
#include <iostream>
#include <string>
#include <vector>
#define mod 1000000007
using namespace std;

int N;
vector<string> words;
string target = "UNIST";
int memo[100001][6];
int dp(int i, int j) {
  if (j == 5) return 1;
  if (i == N) return 0;
  if (memo[i][j] != -1) return memo[i][j];
  int result = 0;
  result = (result + dp(i + 1, j)) % mod;
  const string& word = words[i];
  for (int len = 1; len <= min((int)word.length(), 5 - j); len++) {
    bool match = true;
    for (int k = 0; k < len; k++) {
      if (word[k] != target[j + k]) {
        match = false;
        break;
      }
    }
    if (match) {
      result = (result + dp(i + 1, j + len)) % mod;
    }
  }

  return memo[i][j] = result;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> N;
  words.resize(N);
  for (int i = 0; i < N; i++) {
    cin >> words[i];
  }
  memset(memo, -1, sizeof(memo));
  int answer = dp(0, 0);
  cout << answer << "\n";
  return 0;
}