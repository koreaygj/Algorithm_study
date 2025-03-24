#include <iostream>
using namespace std;
int Cnt;
int Visited[31];
void findArr(int n, int *arr, int s, int sub_cnt, int prev, int sum) {
  if (sum == s && sub_cnt != 0) Cnt++;
  for (int i = prev + 1; i < n; i++) {
    if (Visited[i]) continue;
    Visited[i] = true;
    findArr(n, arr, s, sub_cnt + 1, i, sum + arr[i]);
    Visited[i] = false;
  }
}
int main() {
  int n, s;
  cin >> n >> s;
  int arr[21] = {0};
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  findArr(n, arr, s, 0, -1, 0);
  cout << Cnt << "\n";
}
