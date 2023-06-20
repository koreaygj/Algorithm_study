#include <bits/stdc++.h>
using namespace std;
int Arr[100001];
bool visited[100001];
bool check[100001];
int cnt;
void dfs(int cur){
    visited[cur] = true;
    int next = Arr[cur];
    if(!visited[next]){
         dfs(next);
    }
    else if(!check[next]){
        for(int i = next; i != cur; i = Arr[i])
            cnt++;
        cnt++;
    }
    check[cur] = true;
}
int solution(){
    memset(Arr, 0, sizeof(Arr));
    memset(visited, 0, sizeof(visited));
    memset(check, 0, sizeof(check));
    int n;
    int ans = 0;
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> Arr[i];
    }
    cnt = 0;
    for(int i = 1; i <= n; i++){
        if(!visited[i])
            dfs(i);
    }
    return n - cnt;
}
int main(void){
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    for(int i = 0; i < T; i++){
        cout << solution() << "\n";
    }
}