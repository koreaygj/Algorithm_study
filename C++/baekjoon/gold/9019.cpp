#include <bits/stdc++.h>
using namespace std;
bool visited[10001];
struct block{
    int n;
    string path;
};
int D(int n){
    return n * 2 % 10000;
}
int S(int n){
    if(n == 0)
        return 9999;
    return n - 1;
}
int L(int n){
    int front = n % 1000;
    int back = n / 1000;
    return front * 10 + back;
}
int R(int n){
    int front = n % 10;
    int back = n / 10;
    return front * 1000 + back;
}
string bfs(int a, int b){
    queue<block> q;
    q.push({a, ""});
    while(!q.empty()){
        block cur = q.front();
        q.pop();
        if(cur.n < 0 || cur.n >= 10000)
            continue;
        if(cur.n == b)
            return cur.path;
        if(!visited[D(cur.n)]){
            visited[D(cur.n)] = 1;
            q.push({D(cur.n), cur.path + "D"});
        }
        if(!visited[S(cur.n)]){
            visited[S(cur.n)] = 1;
            q.push({S(cur.n), cur.path + "S"});
        }
        if(!visited[L(cur.n)]){
            visited[L(cur.n)] = 1;
            q.push({L(cur.n), cur.path + "L"});
        }
        if(!visited[R(cur.n)]){
            visited[R(cur.n)] = 1;
            q.push({R(cur.n), cur.path + "R"});
        }
    }
    return "";
}
int main(void){
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    for(int i = 0; i < t; i++){
        int a, b;
        memset(visited, 0, sizeof(visited));
        cin >> a >> b;
        cout << bfs(a, b) << "\n";
    }
}