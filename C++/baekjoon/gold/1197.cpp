#include <bits/stdc++.h>
using namespace std;
struct trunk{
    int st;
    int end;
    int cost;
};
bool comp(trunk a, trunk b){
    return a.cost < b.cost;
}
class Tree{
    int v;
    int e;
    int ans, cnt = 0;
    int find(int x);
    bool Union(int x, int y);
    int parent[100001];
    vector<trunk> node;  
    void dfs();
    public:
        void input();
        void print(){
            cout << ans << "\n";
        }
};
void Tree::input(){
    cin >> v >> e;
    for(int i = 0; i < e; i++){
        int a, b, c;
        cin >> a >> b >> c;
        node.push_back({a, b, c});
        node.push_back({b, a, c});
    }
    for(int i = 0; i < v + 1; i++)
        parent[i] = i;
    sort(node.begin(), node.end(), comp);
    dfs();
}
int Tree::find(int x){
    if(parent[x] == x)
        return x;
    else{
        int y = find(parent[x]);
        return y;
    }
}
bool Tree::Union(int x, int y){
    x = find(x);
    y = find(y);
    if(x == y){
        return true;
    }
    else{
        if(x < y)
            parent[y] = x;
        else
            parent[x] = y;
        return false;
    }
}
void Tree::dfs(){
    for(int i = 0; i < node.size(); i++){
        trunk cur = node[i];
        if(find(cur.st) == find(cur.end))
            continue;
        ans += cur.cost;
        ++cnt;
        Union(cur.st, cur.end);
        if(cnt == v -1)
            return;
    }
}
int main(void){
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
    Tree mst;
    mst.input();
    mst.print();
}