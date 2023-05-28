#include<bits/stdc++.h>
using namespace std;
struct land{
    int st;
    int end;
    int length;
};
bool comp(land a, land b){
    return a.length < b.length;
}
class bridge{
    int n, m;
    int map[11][11] = {0};
    bool visited[11][11] = {0};
    int parent[11];
    bool Union(int x, int y);
    int find_parent(int x);
    void find_land();
    void dfs(int x, int y, int cnt);
    void length(int x, int y, int now);
    bool kruskal(int cnt, int bgnum);
    vector<land> bg;
    int ans = 0;
    pair<int, int> path[4] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    public:
        void input();
};
void bridge::input(){
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++)
            cin >> map[i][j];
    }
    find_land();
}
int bridge::find_parent(int x){
    if(x == parent[x])
        return x;
    else{
        int y = find_parent(parent[x]);
        return y;
    }
}
bool bridge::Union(int x, int y){
    x = find_parent(x);
    y = find_parent(y);
    if(x == y)
        return true;
    else{
        if(x < y)
            parent[y] = x;
        else
            parent[x] = y;
        return false;
    }
}
void bridge::find_land(){
    int cnt = 1;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(map[i][j] != 0 && !visited[i][j]){
                visited[i][j] = 1;
                map[i][j] = cnt;
                dfs(i, j, map[i][j]);
                cnt++;
            }
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(map[i][j] != 0){
                length(i, j, map[i][j]);
            }
        }
    }
    for(int i = 0; i < cnt; i++){
        parent[i] = i;
    }
    sort(bg.begin(), bg.end(), comp);
    if(kruskal(0, cnt - 2))
        cout << ans << "\n";
    else    
        cout << "-1\n";
}
void bridge::dfs(int x, int y, int cnt){
    for(int i = 0; i < 4; i++){
        int n_x = x + path[i].first;
        int n_y = y + path[i].second;
        if(n_x < 0 || n_x > n || n_y < 0 || n_y > m || visited[n_x][n_y])
            continue;
        if(map[n_x][n_y] != 0){
            visited[n_x][n_y] = 1;
            map[n_x][n_y] = cnt;
            dfs(n_x, n_y, cnt);
        }
    }
    return;
}
void bridge::length(int x, int y, int now){
    for(int i = 0; i < 4; i++){
        int dist = 0;
        int next_x = x;
        int next_y = y;
        while(1){
            next_x += path[i].first;
            next_y += path[i].second;
            if(next_x < 0 || next_x > n || next_y < 0 || next_y > m || map[next_x][next_y] == now)
                break;
            if(map[next_x][next_y] != 0){
                if(dist > 1){
                    bg.push_back({now, map[next_x][next_y], dist});
                }
                break;
            }
            dist++;
        }
    }
}
bool bridge::kruskal(int cnt, int bgnum){
    for(int i = 0; i < bg.size(); i++){
        land cur = bg[i];
        if(find_parent(cur.st) != find_parent(cur.end)){
            ans += cur.length;
            cnt++;
            Union(cur.st, cur.end);
            if(cnt == bgnum)
                return true;
        }
    }
    return false;
}
int main(void){
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
    bridge bg;
    bg.input();
}