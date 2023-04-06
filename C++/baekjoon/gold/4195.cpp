#include <bits/stdc++.h>
using namespace std;
map<string, string> Parent;
map<string, int> Net;
void Insert(string x){
    auto index = Parent.find(x);
    if(index == Parent.end()){
        Parent.insert({x, x});
        Net.insert({x, 1});
    }
    return;
}
string Find(string x){
    if(x == Parent[x])
        return x;
    else{
        string y = Find(Parent[x]);
        Parent[x] = y;
        return y;
    }
}
void Union(string x, string y){
    x = Find(x);
    y = Find(y);
    if(x == y)
        return;
    else{
        if(Net[x] < Net[y]){
            Parent[x] = y;
            Net[y] += Net[x];
        }
        else{
            Parent[y] = x;
            Net[x] += Net[y];
        }
    }
    return;
}
int main(void){
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    for(int i = 0; i < t; i++){
        int n;
        cin >> n;
        Parent.clear();
        Net.clear();
        for(int j = 0; j < n; j++){
            string a, b;
            cin >> a >> b;
            Insert(a);
            Insert(b);
            Union(a, b);
            cout << Net[Find(b)] << "\n";
        }
    }
}