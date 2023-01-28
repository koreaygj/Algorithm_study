#include <bits/stdc++.h>
using namespace std;
int dots[100005];
struct comp {
    bool operator()(pair<int, int> a, pair<int, int> b) {
        return a.second > b.second;
    }
};
bool check(int a){
    if(a < 0 || a > 100000)
        return false;
    return true;
}
int dijkstra(int n, int k){
    for(int i = 0; i < 100005; i++)
        dots[i] = 987654321;
    priority_queue<pair<int, int>, vector<pair<int, int>>, comp> q;
    dots[n] = 0;
    q.push({n, 0});
    while(!q.empty()){
        pair<int, int> cur = q.top();
        q.pop();
        if(dots[cur.first] < cur.second)
            continue;
        int a = cur.first - 1;
        int b = cur.first + 1;
        int c = cur.first * 2;
        if(check(c)){
            if(cur.second < dots[c]){
                dots[c] = cur.second;
                q.push({c, cur.second});
            }
        }
        if(check(a)){
            if(cur.second + 1 < dots[a]){
                dots[a] = cur.second + 1;
                q.push({a, cur.second + 1});
            }
        }
        if(check(b)){
            if(cur.second + 1 < dots[b]){
                dots[b] = cur.second + 1;
                q.push({b, cur.second + 1});
            }
        }
    }
    return dots[k];
}
int main(void){
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
    int n, k;
    cin >> n >> k ;
    cout << dijkstra(n, k) << "\n";
}