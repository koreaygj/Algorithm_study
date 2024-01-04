#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;
int main(void){
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
    int n;
    int arr[1000001] = {0};
    int dp[1000001] = {0};
    stack<int> st;
    cin >> n;
    int answer[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        dp[arr[i]]++;
    }
    for(int i = n - 1; i >= 0; i--){
        int index = dp[arr[i]];
        bool flag = false;
        while(!st.empty()){
            if(dp[st.top()] > index){
                flag = true;
                answer[i] = st.top();
                break;
            }
            else{
                st.pop();
            }
        }
        if(flag == false)
            answer[i] = -1;
        st.push(arr[i]);
    }
    for(int ans : answer)
        cout << ans << " ";
    cout << "\n";
}