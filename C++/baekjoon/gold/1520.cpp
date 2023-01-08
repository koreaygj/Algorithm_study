#include <iostream>
#include <algorithm>
using namespace std;
int map[501][501];
int memo[501][501];
bool visit[501][501];
int m, n;
int solution(int x, int y){
    pair<int, int> check[4] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
    if(x == m - 1 && y == n - 1)
        return 1;
    if(visit[x][y]){
        return memo[x][y];
    }
    for(int i = 0; i < 4; i++){
        int next_x = x + check[i].first;
        int next_y = y + check[i].second;
        if(next_x < 0 || next_y < 0 || next_x > m || next_y > n){
            continue;
        }
        if(map[x][y] > map[next_x][next_y]){
            memo[x][y] += solution(next_x, next_y);
        }
    }
    visit[x][y] = true;
    return memo[x][y];
}
int main(void){
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
    cin >> m >> n;
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            cin >> map[i][j];
        }
    }
    cout << solution(0, 0) << "\n";
}