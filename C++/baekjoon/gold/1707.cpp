#include <bits/stdc++.h>
using namespace std;
int visited[20001];
vector<vector<int>> trunk(20001, vector<int> (0, 0));
bool dfs(int st, int group){
    visited[st] = group;
    bool check = true;
    for(int i = 0; i < trunk[st].size(); i++){
        int next = trunk[st][i];
        if(visited[next] == group){
            return false;
        }
        else if(visited[next] == 0)
            check = dfs(next, group * -1);
    }
    return check;
}
int main(void){
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
    int k;
    cin >> k;
    for(int i = 0; i < k; i++){
        int v, e;
        bool ans = true;
        vector<vector<int>> reset(20001, vector<int> (0, 0));
        cin >> v >> e;
        for(int j = 0; j < e; j++){
            int a, b;
            cin >> a >> b;
            trunk[a].push_back(b);
            trunk[b].push_back(a);
        }
        for(int j = 0; j <= v; j++){
            if(ans == true && visited[j] == 0)
                ans = dfs(j, 1);
            cout << ans << endl;
        }
        if(ans == true)
            cout << "YES\n";
        else
            cout << "NO\n";
        memset(visited, 0, sizeof(visited));
        trunk = reset;
    }
}