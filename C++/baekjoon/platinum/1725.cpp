#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;
int main(void){
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
    int n;
    int arr[100001];
    int ans = 0;
    stack<int> st;
    st.push(0);
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> arr[i];
    }
    for(int i = 1; i <= n + 1; i++){
        while(!st.empty() && arr[st.top()] > arr[i]){
            int index = st.top();
            st.pop();
            ans = max(ans, arr[index] * (i - st.top() - 1));
        }
        st.push(i);
    }
    cout << ans << endl;
}