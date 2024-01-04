#include <bits/stdc++.h>
using namespace std;
int board[105];
int cnt[105];
int bfs(int st){
    queue<int> q;
    int dice[6] = {1, 2, 3, 4, 5, 6};
    q.push(st);
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        if(cur > 100)
            continue;
        for(int i = 0; i < 6; i++){
            int next = cur + dice[i];
            if(board[next] != 0)
                next = board[next];
            if(board[next] == 0 && cnt[next] == 0){
                cnt[next] = cnt[cur] + 1;
                q.push(next);
            }
        }
    }
    return cnt[100];
}
int main(void){
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        int a, b;
        cin >> a >> b;
        board[a] = b;
    }
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        board[a] = b;
    }
    cout << bfs(1) << "\n";
}