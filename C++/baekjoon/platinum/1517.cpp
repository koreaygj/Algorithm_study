#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> arr(500005, 0);
vector<int> temp(500005, 0);
long long int cnt;
void merge_sort(int st, int mid, int end){
    int left_st = st;
    int rigth_st = mid + 1;
    int index = st;
    while(left_st <= mid && rigth_st <= end){
        if(arr[left_st] <= arr[rigth_st])
            temp[index++] = arr[left_st++];
        else{
            temp[index++] = arr[rigth_st++];
            cnt += mid - left_st + 1;
        }
    }
    while(left_st <= mid)
        temp[index++] = arr[left_st++];
    while(rigth_st <= end)
        temp[index++] = arr[rigth_st++];
    for(int i = st; i <= end; i++)
        arr[i] = temp[i];
}
void divide(int st, int end){
    if(st >= end)
        return;
    int mid = (st + end) / 2;
    divide(st, mid);
    divide(mid + 1, end);
    merge_sort(st, mid, end);
}
int main(void){
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    divide(0, n - 1);
    cout << cnt << "\n";
}