#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> trunk(100001, vector<int>(0, 0));
int visited[100001];
int N, cnt;
void dfs(int r){
    if(visited[r] != 0)
        return;
    visited[r] = ++cnt;
    for(int i = 0; i < trunk[r].size(); i++){
        if(!visited[trunk[r][i]]){
            dfs(trunk[r][i]);
        }
    }
}
int main(void){
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
    int m, r;
    cin >> N >> m >> r;
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        trunk[a].push_back(b);
        trunk[b].push_back(a);
    }
    for(int i = 1; i <= N; i++)
        sort(trunk[i].begin(), trunk[i].end(), greater<>());
    dfs(r);
    for(int i = 1; i <= N; i++){
        cout << visited[i] << "\n";
    }
}