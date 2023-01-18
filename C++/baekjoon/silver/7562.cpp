#include <bits/stdc++.h>
using namespace std;
int bfs(int l, pair<int, int> cur, pair<int, int> dst){
    if(cur == dst)
        return 0;
    int board[l + 1][l + 1];
    memset(board, 0, sizeof(board));
    pair<int, int> move[8] = {{-1, 2}, {1, 2}, {2, 1}, {2, -1}, {1, -2}, {-1, -2}, {-2, -1}, {-2, 1}};
    queue<pair<int, int>> q;
    q.push(cur);
    while(!q.empty()){
        pair<int, int> now = q.front();
        q.pop();
        for(int i = 0; i < 8; i++){
            pair<int, int> next = {now.first + move[i].first, now.second + move[i].second};
            if(next.first >= l || next.first < 0 || next.second >= l || next.second < 0)
                continue;
            if(board[next.first][next.second] == 0){
                board[next.first][next.second] = board[now.first][now.second] + 1;
                q.push(next);
            }
            if(next == dst)
                break;
        }
    }
    return board[dst.first][dst.second];
}
int main(void){
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    for(int i = 0; i < t; i++){
        int l;
        pair<int, int> cur, dst;
        cin >> l;
        cin >> cur.first >> cur.second;
        cin >> dst.first >> dst.second;
        cout << bfs(l, cur, dst) << "\n";
    }
}