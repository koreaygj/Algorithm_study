#include <bits/stdc++.h>
#define INF LONG_MAX
using namespace std;
int arr[100001];
void point(int st, int end, pair<int, int> mate, long long int ans){
    if(st >= end){
        cout << arr[mate.first] << " " << arr[mate.second] << "\n";
        return;
    }
    if(ans > abs(arr[st] + arr[end])){
        ans = abs(arr[st] + arr[end]);
        mate = {st, end};
    }
    if(arr[st] + arr[end] > 0)
        point(st, end - 1, mate, ans);
    else if(arr[st] + arr[end] <= 0)
        point(st + 1, end, mate, ans);
    return;
}
int main(void){
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    sort(arr, arr + n);
    point(0, n - 1, {0, 0}, INF);
}