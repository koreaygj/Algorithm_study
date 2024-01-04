#include <bits/stdc++.h>
using namespace std;
int N;
vector<int> Trunk[1000001];
int Dp[1000001][2];
bool Visited[1000001];
void dfs(int cur){
    Dp[cur][1] = 1;
    Visited[cur] = 1;
    for(int i = 0; i < Trunk[cur].size(); i++){
        int next = Trunk[cur][i];
        if(Visited[next])
            continue;
        dfs(next);
        Dp[cur][1] += min(Dp[next][0], Dp[next][1]);
        Dp[cur][0] += Dp[next][1];
    }
}
int main(void){
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
    cin >> N;
    for(int i = 0; i < N - 1; i++){
        int a, b;
        cin >> a >> b;
        Trunk[a].push_back(b);
        Trunk[b].push_back(a);
    }
    dfs(1);
    cout << min(Dp[1][1], Dp[1][0]) << "\n";
}