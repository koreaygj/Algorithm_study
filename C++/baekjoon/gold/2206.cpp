#include <bits/stdc++.h>
using namespace std;
int N, M;
int Map[1005][1005];
bool Dst[1005][1005][2];
struct point{
    int x;
    int y;
    int cnt;
    int wall;
};
int bfs(){
    point cur = {0, 0, 1};
    point move[4] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    queue<pair<point, int>> q;
    q.push({cur, 1});
    while(!q.empty()){
        point cur = q.front().first;
        int wall = q.front().second;
        q.pop();
        if(cur.x == N - 1 && cur.y == M - 1){
            return cur.cnt;
        }
        for(int i = 0; i < 4; i++){
            point next = {cur.x + move[i].x, cur.y + move[i].y, cur.cnt + 1};
            if(next.x < 0 || next.x > N - 1 || next.y < 0 || next.y > M - 1)
                continue;
            if(!Dst[next.x][next.y][1] && wall == 1){
                if(Map[next.x][next.y] == 1){
                    q.push({next, 0});
                    Dst[next.x][next.y][0] = true;
                }
                else{
                    q.push({next, 1});
                    Dst[next.x][next.y][1] = true;
                }
            }
            else if(!Dst[next.x][next.y][0] && wall == 0){
                if(Map[next.x][next.y] != 1){
                    q.push({next, 0});
                    Dst[next.x][next.y][0] = true;
                }
            }
        }
    }
    return -1;
}
int main(void){
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
    cin >> N >> M;
    for(int i = 0; i < N; i++){
        string a;
        cin >> a;
        for(int j = 0; j < M; j++)
            Map[i][j] = a[j] - '0';
    }
    Dst[0][0][0] = 1;
    Dst[0][0][1] = 1;
    cout << bfs() << "\n";
}