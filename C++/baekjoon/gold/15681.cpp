#include <bits/stdc++.h>
using namespace std;
class Tree{
    int n, r, q;
    vector<int> node[100001];
    bool visited[100001] = {false};
    int dfs(int x);
    int dp[100001] = {0};
    public:
        void input();
};
void Tree::input(){
    cin >> n >> r >> q;
    for(int i = 0; i < n - 1; i++){
        int u, v;
        cin >> u >> v;
        node[u].push_back(v);
        node[v].push_back(u);
    }
    visited[r] = 1;
    dp[r] = dfs(r);
    for(int i = 0; i < q; i++){
        int a;
        cin >> a;
        cout << dp[a] << "\n";
    }
}
int Tree::dfs(int x){
    if(dp[x] != 0)
        return dp[x];
    int cnt = 1;
    for(int i = 0; i < node[x].size(); i++){
        int next = node[x][i];
        if(visited[next])
            continue;
        visited[next] = 1;
        cnt += dfs(next);
    }
    dp[x] = cnt;
    return cnt;
}
int main(void){
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
    Tree a;
    a.input();
}