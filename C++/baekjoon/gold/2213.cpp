#include <bits/stdc++.h>
using namespace std;
class solution{
    int n;
    int w[10001];
    vector<int> trunk[10001];
    int dp[10001][2] = {0, };
    bool visited[10001] = {0};
    void dfs(int cur);
    void trace(int cur, int prev);
    vector<int> path;
    public:
        void input();
};
void solution::input(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> w[i];
    }
    for(int i = 0; i < n - 1; i++){
        int a, b;
        cin >> a >> b;
        trunk[a].push_back(b);
        trunk[b].push_back(a);
    }
    dfs(1);
    cout << max(dp[1][1], dp[1][0]) << "\n";
    memset(visited, 0, sizeof(visited));
    trace(1, 0);
    sort(path.begin(), path.end());
    for(int i = 0; i < path.size(); i++)
        cout << path[i] << " ";
    cout << "\n";
}
void solution::dfs(int cur){
    dp[cur][0] = 0;
    dp[cur][1] = w[cur];
    visited[cur] = 1;
    for(int i = 0; i < trunk[cur].size(); i++){
        int next = trunk[cur][i];
        if(visited[next])
            continue;
        dfs(next);
        dp[cur][0] += max(dp[next][0], dp[next][1]);
        dp[cur][1] += dp[next][0];
    }
}
void solution::trace(int cur, int prev){
    if(dp[cur][1] > dp[cur][0] && !visited[prev]){
        path.push_back(cur);
        visited[cur] = true;
    }
    for(int i = 0; i < trunk[cur].size(); i++){
        int next = trunk[cur][i];
        if(next == prev) continue;
        trace(next, cur);
    }
}
int main(void){
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
    solution s;
    s.input();
}