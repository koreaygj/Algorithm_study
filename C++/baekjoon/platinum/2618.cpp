#include <bits/stdc++.h>
#define INF INT_MAX
using namespace std;
int N, W;
int board[1001][1001];
struct point{
    int x;
    int y;
};
vector<point> Car1;
vector<point> Car2;
int cal_dist(point a, point b){
    return abs(a.x - b.x) + abs(a.y - b.y);
}
int dp(int a, int b){
    if(a == W || b == W)
        return 0;
    int cur = board[a][b];
    int next = max(a, b) + 1;
    if(cur != -1)
        return cur;
    cur = INF;
    int dist1 = dp(next, b) + cal_dist(Car1[next], Car1[a]);
    int dist2 = dp(a, next) + cal_dist(Car2[next], Car2[b]);
    return board[a][b] = min(dist1, dist2);
}
void route(int a, int b){
    if(a == W || b == W)
        return;
    int cur = board[a][b];
    int next = max(a, b) + 1;
    int dist1 = dp(next, b) + cal_dist(Car1[next], Car1[a]);
    int dist2 = dp(a, next) + cal_dist(Car2[next], Car2[b]);
    if(dist1 > dist2){
        cout << "2\n";
        route(a, next);
    }
    else{
        cout << "1\n";
        route(next, b);
    }
}
void solution(){
    cout << dp(0, 0) << "\n";
    route(0, 0);
}
int main(void){
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
    int ans = 0;
    memset(board, -1, sizeof(board));
    cin >> N;
    cin >> W;
    Car1.push_back({1, 1});
    Car2.push_back({N, N});
    for(int i = 0; i < W; i++){
        point cs;
        cin >> cs.x >> cs.y;
        Car1.push_back(cs);
        Car2.push_back(cs);
    }
    solution();
}