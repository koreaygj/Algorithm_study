#include <bits/stdc++.h>
using namespace std;
int Parent[1000001];
int Find(int x){
    if(Parent[x] == x){
        return x;
    }
    else{
        int y = Find(Parent[x]);
        Parent[x] = y;
        return y;
    }
}
void Union(int x, int y){
    x = Find(x);
    y = Find(y);
    if(x == y){
        return;
    }
    else{
        if(x < y){
            Parent[y] = x;
        }
        else
            Parent[x] = y;
    }
}
bool is_Union(int x, int y){
    x = Find(x);
    y = Find(y);
    if(x == y)
        return true;
    return false;
}
int main(void){
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    for(int i = 0; i <= n; i++){
        Parent[i] = i;
    }
    for(int i = 0; i < m; i++){
        int a, b, c;
        cin >> a;
        if(a == 1){
            cin >> b >> c;
            if(is_Union(b, c))
                cout << "YES\n";
            else
                cout << "NO\n";
        }
        else{
            cin >> b >> c;
            Union(b, c);
        }
    }
}