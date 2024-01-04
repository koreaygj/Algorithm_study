#include<bits/stdc++.h>
using namespace std;
int N;
vector<int> tree[100001];
void solution(){
    int ans[100001] = {0};
    queue<int> q;
    q.push(1);
    while(!q.empty()){
        int parent;
        parent = q.front();
        q.pop();
        for(int i = 0; i < tree[parent].size(); i++){
            int child = tree[parent][i];
            if(ans[child] == 0){
                ans[child] = parent;
                q.push(child);
            }
        }
    }
    for(int i = 2; i <= N; i++){
        cout << ans[i] << "\n";
    }
    return;
}
int main(void){
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
    cin >> N;
    for(int i = 1; i < N; i++){
        int a, b;
        cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    solution();
    return 0;
}