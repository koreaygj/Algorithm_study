#include <bits/stdc++.h>
#define INF LONG_LONG_MAX
using namespace std;
struct bus{
    int stop;
    long long int cost;
    bool operator<(const bus b) const{
        return this -> cost > b.cost;
    }
};
vector<bus> djikstra(int n, int st, int end, vector<vector<bus>> graph){
    vector<bus> dist(n + 1, {0, INF});
    priority_queue<bus> pq;
    pq.push({st, 0});
    while(!pq.empty()){
        bus cur = pq.top();
        pq.pop();
        if(dist[cur.stop].cost < cur.cost)
            continue;
        for(int i = 0; i < graph[cur.stop].size(); i++){
            bus next = graph[cur.stop][i];
            next.cost += cur.cost;
            if(dist[next.stop].cost > next.cost){
                dist[next.stop] = {cur.stop, next.cost};
                pq.push(next);
            }
        }

    }
    return dist;
}
int main(void){
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
    int n, m;
    cin >> n;
    cin >> m;
    vector<vector<bus>> graph(n + 1, vector<bus>());
    for(int i = 0; i < m; i++){
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back({b, c});
    }
    int st, end;
    cin >> st >> end;
    vector<bus> ans = djikstra(n, st, end, graph);
    cout << ans[end].cost << "\n";
    int city = 1;
    vector<int> path;
    path.push_back(end);
    while(1){
        end = ans[end].stop;
        city++;
        path.push_back(end);
        if(end == st)
            break;
    }
    cout << city << "\n";
    for(int i = city - 1; i >= 0; i--)
        cout << path[i] << " ";
    cout << "\n";
}