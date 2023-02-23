#include <bits/stdc++.h>
#define INF INT_MAX
using namespace std;
int N, K;
int dp[100001];
int visited[100001];
void bfs(int st){
    queue<int> path;
    path.push(st);
    while(!path.empty())
    {
        int cur = path.front();
        if(cur == K)
            return;
        path.pop();
        vector<int> move = { cur - 1, cur + 1, cur * 2};
        for(int i = 0;i < 3; i++)
        {
            int next = move[i];
            if(next < 0 || next > 100000 || visited[next] != -1)
                continue;
            if(dp[next] != 0){
                dp[next] = min(dp[next] , dp[cur] + 1);
                if(dp[next] >= dp[cur] + 1)
                    visited[next] = cur;
            }
            else{
                dp[next] = dp[cur] + 1;
                visited[next] = cur;
            }
            path.push(next);
        }
    }
}
int main(void){
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
    memset(visited, -1, sizeof(visited));
    cin >> N >> K;
    bfs(N);
    cout << dp[K] << "\n";
    vector<int> ans;
    queue<int> q;
    ans.push_back(K);
    q.push(K);
    while(!q.empty()){
        int st = q.front();
        if(st == N)
            break;
        q.pop();
        int next = visited[st];
        ans.push_back(next);
        q.push(next);
    }
    for(int i = ans.size() - 1; i >= 0; i--)
        cout << ans[i] << " ";
    cout << "\n";
}