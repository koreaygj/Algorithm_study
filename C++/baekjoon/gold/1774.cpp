#include <bits/stdc++.h>
using namespace std;
struct point{
    double x;
    double y;
};
struct trunk{
    int st;
    int end;
    double cost;
};
bool comp(trunk a, trunk b){
    return a.cost < b.cost;
}
class Tree{
    int n;
    int m;
    int cnt = 0;
    double ans = 0;
    int find(int x);
    bool Union(int x, int y);
    double cal_dist(point a, point b);
    void check_dist();
    int parent[1001];
    vector<trunk> node; 
    vector<point> god; 
    void dfs();
    public:
        void input();
        void print(){
            cout << fixed;
            cout.precision(2);
            cout << ans << "\n";
        }
};
double Tree::cal_dist(point a, point b){
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
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
void Tree::input(){
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        double a, b;
        cin >> a >> b;
        god.push_back({a, b});
    }
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        node.push_back({a - 1, b - 1, 0});
        node.push_back({b - 1, a - 1, 0});
    }
    check_dist();
    sort(node.begin(), node.end(), comp);
    for(int i = 0; i < n + 1; i++)
        parent[i] = i;
    dfs();
}
void Tree::check_dist(){
    for(int i = 0; i < n - 1; i++){
        point cur = god[i];
        for(int j = i; j < n; j++){
            point next = god[j];
            double dist = cal_dist(cur, next);
            node.push_back({i, j, dist});
            node.push_back({j, i, dist});
        }
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
        if(cnt == n - 1)
            return;
    }
}
int main(void){
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
    Tree tree;
    tree.input();
    tree.print();
    return 0;
}