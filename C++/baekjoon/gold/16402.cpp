#include <cstdio>
#include <iostream>
#include <map>
#include <vector>
using namespace std;
map<string, string> Kingdom;
void Coup(string a, string b, int winner) {
  string parent = Kingdom[a];
  string next_kingdom = winner == 1 ? a : b;
  if (parent == next_kingdom)
    return;
  else {
    for (auto iter = Kingdom.begin(); iter != Kingdom.end(); iter++)
      if (iter->second == parent) iter->second = next_kingdom;
  }
}
void War(string a, string b, int winner) {
  string parent_a = Kingdom[a];
  string parent_b = Kingdom[b];
  if (parent_a == parent_b) {
    Coup(a, b, winner);
  } else {
    string next_kingdom = winner == 1 ? parent_a : parent_b;
    string prev_kingdom = winner != 1 ? parent_a : parent_b;
    for (auto iter = Kingdom.begin(); iter != Kingdom.end(); iter++)
      if (iter->second == prev_kingdom) iter->second = next_kingdom;
  }
}

int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    char buffer[100];
    scanf("%*s %*s %s", buffer);
    string tmp = buffer;
    Kingdom[tmp] = tmp;
  }

  for (int j = 0; j < m; j++) {
    char bufferA[100], bufferB[100];
    int winner;
    scanf("%*s %*s %[^,], %*s %*s %[^,],%d", bufferA, bufferB, &winner);
    string a = bufferA;
    string b = bufferB;
    War(a, b, winner);
  }

  map<string, int> remain_kingdom;
  for (auto iter = Kingdom.begin(); iter != Kingdom.end(); iter++) {
    remain_kingdom[iter->second];
  }
  cout << remain_kingdom.size() << "\n";
  for (auto iter = remain_kingdom.begin(); iter != remain_kingdom.end();
       iter++) {
    cout << "Kingdom of " << iter->first << "\n";
  }
  return 0;
}