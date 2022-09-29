#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
bool sol(vector<int> array, int check){
    int st = 0;
    int end = array.size() - 1;
    int mid = 0;
    while(st <= end){
        cout << st << " " << end << endl;
        mid = (st + end) / 2;
        if(array[mid] == check)
            return 1;
        else if(array[mid] < check)
            st = mid + 1;
        else
            end = mid - 1;
    }
    return 0;
}
int main(void){
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
    int n, m;
    cin >> n;
    vector<int> arr(n, 0);
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    sort(arr.begin(), arr.end());
    cin >> m;
    for(int i = 0; i < m; i++)
    {
        int a;
        cin >> a;
        cout << sol(arr, a) << "\n";
    }
}