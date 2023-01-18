#include <bits/stdc++.h>
using namespace std;
int M, N, H;
int box[101][101][101];
int cnt[101][101][101];
struct point{
    int x;
    int y;
    int z;
};
int check(){
    int answer = 0;
    for(int i = 0; i < H; i++){
        for(int j = 0; j < N; j++){
            for(int k = 0; k < M; k++){
                if(box[k][j][i] == 0){
                    return -1;
                }
                else if(box[k][j][i] == -1)
                    continue;
                answer = max(answer, cnt[k][j][i]); 
            }
        }
    }
    if(answer == 1)
        return 0;
    return answer - 1;
}
void bfs(){
    queue<point> q; 
    point move[6] = {{-1, 0, 0}, {1, 0, 0}, {0, -1, 0}, {0, 1, 0}, {0, 0, -1}, {0, 0, 1}};
    for(int i = 0; i < H; i++){
        for(int j = 0; j < N; j++){
            for(int k = 0; k < M; k++){
                if(box[k][j][i] == 1){
                    cnt[k][j][i] = 1; 
                    q.push({k, j, i});
                }
            }
        }
    }
    while(!q.empty()){
        point cur = q.front();
        q.pop();
        for(int i = 0; i < 6; i++){
            point next = {cur.x + move[i].x, cur.y + move[i].y, cur.z + move[i].z};
            if(next.x >= M || next.x < 0 || next.y >= N || next.y < 0 || next.z >= H || next.z < 0)
                continue;
            if(box[next.x][next.y][next.z] == 0 && cnt[next.x][next.y][next.z] == 0){
                cnt[next.x][next.y][next.z] = cnt[cur.x][cur.y][cur.z] + 1;
                box[next.x][next.y][next.z] = 1;
                q.push(next);
            }
        }
    }
    cout << check() << "\n";
}
int main(void){
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
    cin >> M >> N >> H;
    for(int i = 0; i < H; i++){
        for(int j = 0; j < N; j++){
            for(int k = 0; k < M; k++){
                cin >> box[k][j][i];
            }
        }
    }
    bfs();
}