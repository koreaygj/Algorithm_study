#include <bits/stdc++.h>
using namespace std;
struct trunk{
    int node;
    int dist;
};
vector<trunk> tree[10001];
bool visited[10001];
int ans;
int flag;
void dfs(int st, int length){
    visited[st] = true;
    for(int i = 0; i < tree[st].size(); i++){
        trunk next = tree[st][i];
        if(visited[next.node] == true)
            continue;
        dfs(next.node, length + next.dist);
    }
    if(ans < length){
        ans = length;
        flag = st;
    }
    return;
}
int main(void){
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    for(int i = 0; i < n - 1; i++){
        int a, b, dist;
        cin >> a >> b >> dist;
        tree[a].push_back({b, dist});
        tree[b].push_back({a, dist});
    }
    dfs(1, 0);
    memset(visited, 0, sizeof(visited));
    dfs(flag, 0);
    cout << ans << "\n";
}