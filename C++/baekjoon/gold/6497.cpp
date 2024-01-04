#include <bits/stdc++.h>
using namespace std;
struct road{
    int st;
    int end;
    int length;
};
bool comp(road a, road b){
    return a.length < b.length;
}
class Tree{
    int n, m;
    int parent[200001];
    vector<road> node;
    long int ans = 0;
    int Find(int x);
    bool Union(int x, int y);
    void kruskal(int cnt);
    public:
        void input(int m, int n);
        void print();
};
void Tree::input(int m, int n){
    m = m;
    n = n;
    for(int i = 0; i < n; i++){
        int x, y, z;
        cin >> x >> y >> z;
        ans += z;
        node.push_back({x, y, z});
        node.push_back({y, x, z});
    }
    for(int i = 0; i <= m; i++)
        parent[i] = i;
    sort(node.begin(), node.end(), comp);
    kruskal(0);
}
int Tree::Find(int x){
    if(parent[x] == x)
        return x;
    else{
        int y = Find(parent[x]);
        return y;
    }
}
bool Tree::Union(int x, int y){
    x = Find(x);
    y = Find(y);
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
void Tree::kruskal(int cnt){
    for(int i = 0; i < node.size(); i++){
        road cur = node[i];
        if(Find(cur.st) != Find(cur.end)){
            ans -= cur.length;
            cnt++;
            Union(cur.st, cur.end);
            if(cnt == n - 1)
                return;
        }
    }
}
void Tree::print(){
    cout << ans << "\n";
}
int main(void){
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
    while(1){
        Tree tree;
        int m, n;
        cin >> m >> n;
        if(m == 0 && n == 0)
            break;
        tree.input(m, n);
        tree.print();
    }
    return 0;
}