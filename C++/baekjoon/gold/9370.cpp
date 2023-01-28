#include <bits/stdc++.h>
using namespace std;
struct trunk{
    int node;
    int length;
};
struct comp{
    bool operator()(trunk a, trunk b){
        return a.length < b.length;
    }
};
int dist[3][2001];
void dijkstra(int st, int node, vector<trunk> *path){
    dist[node][st] = 0;
    priority_queue<trunk, vector<trunk>, comp> pq;
    pq.push({st, 0});
    while(!pq.empty()){
        trunk cur = pq.top();
        pq.pop();
        if(cur.length > dist[node][cur.node])
            continue;
        for(int i = 0; i < path[cur.node].size(); i++){
            trunk next = path[cur.node][i];
            if(next.length + cur.length < dist[node][next.node]){
                dist[node][next.node] = next.length + cur.length;
                pq.push({next.node, dist[node][next.node]});
            }
        }
    }
}
void solution(){
    int n, m, t;
    int s, g, h;
    vector<trunk> path[2005];
    vector<int> ans;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 2001; j++){
            dist[i][j] = 987654321;
        }
    }
    cin >> n >> m >> t;
    cin >> s >> g >> h;
    for(int i = 0; i < m; i++){
        int a, b, d;
        cin >> a >> b >> d;
        path[a].push_back({b, d});
        path[b].push_back({a, d});
    }
    dijkstra(s, 0, path);
    dijkstra(g, 1, path);
    dijkstra(h, 2, path);
    for(int i = 0; i < t; i++){
        int a;
        cin >> a;
        int result = min(dist[0][g] + dist[1][h] + dist[2][a], dist[0][h] + dist[2][g] + dist[1][a]);
        if(dist[0][a] == result)
            ans.push_back(a);
    }
    sort(ans.begin(), ans.end());
    for(int ans: ans)
        cout << ans << " ";
    cout << "\n";
    return;
}
int main(void){
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    for(int i = 0; i < T; i++)
        solution();
}