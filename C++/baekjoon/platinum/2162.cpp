#include<bits/stdc++.h>
using namespace std;
int N;
struct point{
    int x, y;
};
vector<pair<point, point>> Input;
int Parent[3001];
int Find(int x){
    if(x == Parent[x])
        return x;
    else{
        int y = Find(Parent[x]);
        Parent[x] = y;
        return y;
    }
}
bool Union(int x, int y){
    x = Find(x);
    y = Find(y);
    if(x == y){
        return true;
    }
    else{
        if(x < y)
            Parent[y] = x;
        else
            Parent[x] = y;
        return false;
    }
}
int ccw(point a, point b, point c){
    int tmp = (c.x - a.x) * (b.y - a.y) - (c.y - a.y) * (b.x - a.x);
    if(tmp > 0)
        return 1;
    else if(tmp == 0)
        return 0;
    else
        return -1;
}
bool comp(point a, point b){
    if(a.x == b.x)
        return a.y < b.y;
    return a.x < b.x;
}
int main(void){
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
    cin >> N;
    for(int i = 0; i < N; i++){
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        Input.push_back({{a, b}, {c, d}});
        Parent[i] = i;
    }
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            point a, b, c, d;
            a = Input[i].first;
            b = Input[i].second;
            c = Input[j].first;
            d = Input[j].second;
            int cs1 = ccw(a, b, c) * ccw(a, b, d);
            int cs2 = ccw(c, d, a) * ccw(c, d, b);
            if(cs1 == 0 && cs2 == 0){
                if(comp(b, a))
                    swap(a, b);
                if(comp(d, c))
                    swap(c, d);
                if(!comp(d, a) && !comp(b, c)){
                    Union(i, j);
                }
            }
            else{
                if(cs1 <= 0 && cs2 <= 0){
                    Union(i, j);
                }
            }
        }
    }
    int dp[3001] = {0};
    int cnt = 0;
    int ans = 0;
    for(int i = 0; i < N; i++){
        dp[Find(Parent[i])]++;
    }
    for(int i = 0; i < N; i++){
        if(dp[i] != 0){
            cnt++;
            ans = max(ans, dp[i]);
        }
    }
    cout << cnt << "\n";
    cout << ans << "\n";
}