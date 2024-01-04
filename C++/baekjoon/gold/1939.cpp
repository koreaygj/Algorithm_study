#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<pair<int, int>> Input[100001];
vector<bool> Visited(100001, false);
void dfs(int x, int mid){
    for(int i = 0; i < Input[x].size(); i++){
        if(!Visited[Input[x][i].first] && (Input[x][i].second >= mid)){
            Visited[Input[x][i].first] = true;
            dfs(Input[x][i].first, mid);
        }
    }
}
int find_path(int end, int x, int y){
    int st = 0;
    vector<bool> reset(100001, false);
    while(st <= end){
        Visited = reset;
        int mid = (st + end) /2;
        Visited[x] = true;
        dfs(x, mid);
        if(Visited[y])
            st = mid + 1;
        else
            end = mid - 1;
    }
    return end;
}
int main(void){
    int n, m, x, y;
    cin >> n >> m;
    int end = 0;
    for(int i = 0; i < m; i++){
        int a, b, c;
        cin >> a >> b >> c;
        Input[a].push_back({b, c});
        Input[b].push_back({a, c});
        end = max(end, c);
    }
    cin >> x >> y;
    int answer = find_path(end, x, y);
    cout << answer << "\n";
}