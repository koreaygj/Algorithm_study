#include <algorithm>
#include <cstring>
#include <iostream>
#include <map>
using namespace std;
int N, M;
vector<int> Arr;
vector<int> Set;
bool Selected[10];
void dfs(int st, int cnt) {
  if (cnt == M) {
    for (const auto val : Set) {
      cout << val << " ";
    }
    cout << "\n";
    return;
  }
  for (int i = 0; i < N; i++) {
    if (Selected[i]) continue;
    Selected[i] = true;
    Set.push_back(Arr[i]);
    dfs(i + 1, cnt + 1);
    Selected[i] = false;
    Set.pop_back();
  }
}
int main() {
  cin >> N >> M;
  Arr = vector<int>(N, 0);
  for (int i = 0; i < N; i++) {
    cin >> Arr[i];
  }
  sort(Arr.begin(), Arr.end());
  for (int i = 0; i < N; i++) {
    memset(Selected, false, 10);
    Selected[i] = true;
    Set.push_back(Arr[i]);
    dfs(i, 1);
    Selected[i] = false;
    Set.pop_back();
  }
}