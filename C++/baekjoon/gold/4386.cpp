#include <bits/stdc++.h>
using namespace std;
struct point{
    double x;
    double y;
};
bool visited[101];
vector<point> star;
double ans;
double length(point a, point b){
    return sqrt((a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y));
}
double dfs(int cnt){
    int s_size = star.size();
    if(cnt == s_size - 1)
        return ans;
    double min_dist = 10000;
    pair<int, int> index;
    if(cnt == s_size - 1)
        return ans;
    for(int j = 0; j < s_size; j++){
        if(!visited[j])
            continue;
        for(int i = 0; i < s_size; i++){
            if(visited[i])
                continue;
            double dist = length(star[j], star[i]);
            if(min_dist > dist){
                min_dist = dist;
                index = {j, i};
            }
        }
    }
    ans += length(star[index.first], star[index.second]);
    visited[index.second] = 1;
    dfs(++cnt);
    return ans;
}
int main(void){
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        double a, b;
        cin >> a >> b;
        star.push_back({a, b});
    }  
    visited[0] = 1;
    cout << dfs(0) << "\n";
    return 0;
}