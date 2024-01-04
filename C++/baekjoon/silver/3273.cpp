#include <bits/stdc++.h>
using namespace std;
int arr[100001];
int point(int st, int end, int x, int cnt){
    if(st >= end)
        return cnt;
    if(arr[st] + arr[end] > x)
        return point(st, end - 1, x, cnt);
    else if(arr[st] + arr[end] < x)
        return point(st + 1, end, x, cnt);
    else{
        return point(st + 1, end, x, cnt + 1);
    }
    return cnt;
}
int main(void){
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
    int n, x;
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    cin >> x;
    sort(arr, arr + n);
    cout << point(0, n - 1, x, 0) << "\n";
}