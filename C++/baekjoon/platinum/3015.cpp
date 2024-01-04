#include <bits/stdc++.h>
using namespace std;
const int INF = 987654321;
int main(void){
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
    int n;
    long long int arr[500001];
    fill_n(arr, 500001, 0);
    cin >> n;
    stack<pair<int, int>> st;
    long long int ans = 0;
    for(int i = 0; i < n; i++){
        int cur;
        int same = 1;
        cin >> cur;
        while(!st.empty() && st.top().first < cur){
            ans += st.top().second;
            st.pop();
        }
        if(!st.empty()){
            if(st.top().first == cur){
                ans += st.top().second;
                same += st.top().second;
                if(st.size() > 1)
                    ans++;
                st.pop();
            }
            else{
                ans++;
            }
        }
        st.push({cur, same});
    }
    cout << ans << "\n";
}