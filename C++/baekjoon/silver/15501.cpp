#include <algorithm>
#include <iostream>
using namespace std;
int* Reverse_arr(int size, int arr[]) {
  int* rv = (int*)malloc(size * sizeof(int));
  if (rv == NULL) return NULL;
  for (int i = 0; i < size; i++) rv[i] = arr[size - i - 1];
  return rv;
}
bool check_puzzle(int n, int first[], int second[]) {
  int* rv_second = Reverse_arr(n, second);
  int st_index_second = -1, st_index_rv = -1;
  for (int i = 0; i < n; i++) {
    if (first[0] == second[i]) st_index_second = i;
    if (first[0] == rv_second[i]) st_index_rv = i;
  }
  if (st_index_rv == -1) return false;
  int cnt = 0;
  int match_cnt[2] = {0, 0};
  while (cnt < n) {
      if (first[cnt] == second[(st_index_second + cnt) % n]) match_cnt[0]++;
    if (first[cnt] == rv_second[(st_index_rv + cnt) % n]) match_cnt[1]++;
    cnt++;
  }
  return match_cnt[0] == n || match_cnt[1] == n;
}
int main() {
  int n;
  cin >> n;
  int first[n];
  int second[n];
  for (int i = 0; i < n; i++) cin >> first[i];
  for (int i = 0; i < n; i++) cin >> second[i];
  bool result = check_puzzle(n, first, second);
  if (result)
    cout << "good puzzle\n";
  else
    cout << "bad puzzle\n";
}