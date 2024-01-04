#include<bits/stdc++.h>
using namespace std;
vector<pair<int, int>> bbq;
vector<pair<int, int>> home;
vector<pair<int, int>> sct;
int n, m;
bool visited[105];
int ans = 987654321;
int path(pair<int, int> a, pair<int, int> b){
    return abs(a.first - b.first) + abs(a.second - b.second);
}
int cal(){
    int result = 0;
    for(int i = 0; i < home.size(); i++){
        int length = 987654321;
        for(int j = 0; j < m; j++){
            length = min(length, path(home[i], sct[j]));
        }
        result += length;
    }
    return result;
}
void select(int index, int cnt){
    if(cnt == m){
        ans = min(ans, cal());
        return;
    }
    for(int i = index; i < bbq.size(); i++){
        if(visited[i])
            continue;
        visited[i] = 1;
        sct.push_back(bbq[i]);
        select(i, cnt + 1);
        visited[i] = 0;
        sct.pop_back();
    }
}
int main(void){
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
    int board[55][55];
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> board[i][j];
            if(board[i][j] == 2)
                bbq.push_back({i, j});
            if(board[i][j] == 1)
                home.push_back({i, j});
        }
    }
    select(0, 0);
    cout << ans << "\n";
}