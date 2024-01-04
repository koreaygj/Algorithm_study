#include <bits/stdc++.h>
using namespace std;
int bfs(int n, int m){
    vector<int> graph[1001];
    bool visited[1001] = {0};
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    queue<int> q;
    q.push(1);
    visited[1] = 1;
    int cnt = 0;
    while(!q.empty()){
        int st = q.front();
        q.pop();
        for(int i = 0 ; i < graph[st].size(); i++){
            int next = graph[st][i];
            if(!visited[next]){
                q.push(next);
                visited[next] = 1;
                cnt++;
            }
        }
    }
    return cnt;
}
int main(void){
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    int n, m;
    for(int i = 0; i < t; i++){
        cin >> n >> m;
        cout << bfs(n, m) << "\n";
    }
    return 0;
}