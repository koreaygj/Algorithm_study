#include <bits/stdc++.h>
using namespace std;
int N;
int Weight[10001];
bool Visited[10001];
int memo[10001][2];
vector<int> Trunk[10001];
void dfs(int cur){
    memo[cur][0] = 0;
    memo[cur][1] = Weight[cur];
    Visited[cur] = 1;
    for(int i = 0; i < Trunk[cur].size(); i++){
        int next = Trunk[cur][i];
        if(Visited[next])
            continue;
        dfs(next);
        memo[cur][0] += max(memo[next][0], memo[next][1]);
        memo[cur][1] += memo[next][0];
    }
}
int main(void){
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
    cin >> N;
    for(int i = 1; i <= N; i++)
        cin >> Weight[i];
    for(int i = 0; i < N - 1; i++){
        int a, b;
        cin >> a >> b;
        Trunk[a].push_back(b);
        Trunk[b].push_back(a);
    }
    dfs(1);
    cout << max(memo[1][1], memo[1][0]) << "\n";
}