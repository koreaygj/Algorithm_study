#include <bits/stdc++.h>
using namespace std;
int solution(vector<int> arr){
    vector<int> LIS;
    vector<int> ans;
    int dp[1000001] = {0};
    int length = 0;
    LIS.push_back(-1000000001);
    for(int i = 0; i < arr.size(); i++){
        if(LIS.back() < arr[i]){
            LIS.push_back(arr[i]);
            dp[i] = LIS.size() - 1;
        }
        else{
            int left = 0;
            int right = LIS.size();
            while(left < right){
                int mid = (left + right) / 2;
                if(LIS[mid] < arr[i]){
                    left = mid + 1;
                }
                else{
                    right = mid;
                }
            }
            LIS[right] = arr[i];
            dp[i] = right;
        }
    }
    length = LIS.size() - 1;
    cout << length << "\n";
    for(int i = arr.size() - 1; i >= 0; i--){
        if(length == dp[i]){
            ans.push_back(arr[i]);
            length--;
        }
    }
    sort(ans.begin(), ans.end());
    for(int ans : ans)
        cout << ans << " ";
    cout << "\n";
    return LIS.size();
}
int main(void){
    int n;
    cin >> n;
    vector<int> arr(n, 0);
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    solution(arr);
}