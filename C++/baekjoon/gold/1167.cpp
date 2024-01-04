#include <bits/stdc++.h>
using namespace std;
struct trunk{
    int node;
    int dist;
};
vector<trunk> tree[100001];
bool visited[100001];
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
    int V;
    cin >> V;
    for(int i = 0; i < V; i++){
        int node;
        cin >> node;
        while(1){
            int a, b;
            cin >> a;
            if(a == -1)
                break;
            cin >> b;
            tree[node].push_back({a, b});
        }
    }
    dfs(1, 0);
    memset(visited, 0, sizeof(visited));
    dfs(flag, 0);
    cout << ans << "\n";
}