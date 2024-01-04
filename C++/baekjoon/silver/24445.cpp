#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> trunk(100001, vector<int>(0, 0));
int visited[100001];
void bfs(int r){
    int cnt = 0;
    queue<int> deque;
    visited[r] = ++cnt;
    deque.push(r);
    while(!deque.empty()){
        int cur = deque.front();
        deque.pop();
        for(int i = 0; i < trunk[cur].size(); i++){
            int next = trunk[cur][i];
            if(visited[next] == 0){
                visited[next] = ++cnt;
                deque.push(next);
            }
        }
    }
}
int main(void){
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
    int n, m, r;
    cin >> n >> m >> r;
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        trunk[a].push_back(b);
        trunk[b].push_back(a);
    }
    for(int i = 1; i <= n; i++)
        sort(trunk[i].begin(), trunk[i].end(), greater<>());
    bfs(r);
    for(int i = 1; i <= n; i++)
        cout << visited[i] << "\n";
}