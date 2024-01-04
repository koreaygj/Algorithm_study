#include <bits/stdc++.h>
using namespace std;
struct trunk{
    int node;
    long long length;
};
struct cmp{
    bool operator()(trunk a, trunk b){
        return a.length < b.length;
    }
};
int N, E;
vector<trunk> path[805];
long long dist[3][805];
void dijkstra(int st, int cs){
    for(int i = 0; i < 3; i++){
        for(int j = 0 ; j < 805; j++){
            dist[i][j] = 987654321;
        }
    }
    dist[cs][st] = 0;
    priority_queue<trunk, vector<trunk>, cmp> pq;
    pq.push({st, 0});
    while(!pq.empty()){
        trunk cur = pq.top();
        pq.pop();
        if(cur.length > dist[cs][cur.node])
            continue;
        for(int i = 0; i < path[cur.node].size(); i++){
            trunk next = path[cur.node][i];
            if(cur.length + next.length < dist[cs][next.node]){
                dist[cs][next.node] = cur.length + next.length;
                pq.push({next.node, dist[cs][next.node]});
            }
        }
    }
}
long long solution(int u, int v){
    long long answer = 0;
    dijkstra(1, 0);
    long long first = dist[0][u];
    long long second = dist[0][v];
    dijkstra(u, 1);
    first += dist[1][v];
    second += dist[1][N];
    dijkstra(v, 2);
    first += dist[2][N];
    second += dist[2][u];
    if(min(first, second) >= 987654321){
        return -1;
    }
    return min(first, second);
}
int main(void){
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
    int u, v;
    cin >> N >> E;
    for(int i = 0; i < E; i++){
        int a, b, c;
        cin >> a >> b >> c;
        path[a].push_back({b, c});
        path[b].push_back({a, c});
    }
    cin >> u >> v;
    cout << solution(u, v) << "\n";
}