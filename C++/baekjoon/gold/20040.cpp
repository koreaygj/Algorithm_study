#include <bits/stdc++.h>
using namespace std;
int Parent[500001];
int Find(int x){
    if(Parent[x] == x)
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
int main(void){
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
    int n, m;
    int ans = 0;
    cin >> n >> m;
    for(int i = 0; i <= n; i++){
        Parent[i] = i;
    }
    for(int i = 1; i <= m; i++){
        int a, b;
        cin >> a >> b;
        if(Union(a, b) && ans == 0){
            ans = i;
        }
    }
    cout << ans << "\n";
}