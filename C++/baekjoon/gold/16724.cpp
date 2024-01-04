#include <bits/stdc++.h>
using namespace std;
int N, M;
char board[1001][1001];
bool visited[1001][1001];
bool check[1001][1001];
int ans;
void dfs(int x, int y){
    visited[x][y] = 1;
    char path[4] = {'U', 'D', 'L', 'R'};
    pair<int, int> step[4] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    for(int i = 0; i < 4; i++){
        if(board[x][y] == path[i]){
            int next_x = x + step[i].first;
            int next_y = y + step[i].second;
            if(!visited[next_x][next_y])
                dfs(next_x, next_y);
            else if(!check[next_x][next_y]){
                ans++;
            }
        }
    }
    check[x][y] = 1;
}
int main(void){
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
    cin >> N >> M;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++)
            cin >> board[i][j];
    }
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(!visited[i][j])
                dfs(i, j);
        }
    }
    cout << ans << "\n";
}