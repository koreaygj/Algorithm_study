#include <bits/stdc++.h>
#define INF 987654321
using namespace std;
int Graph[101][101];
vector<vector<vector<int>>> path(101, vector<vector<int>> (101, vector<int>(0, 0)));
void floyd(int n){
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            for(int k = 1; k <= n; k++){
                if(j == k)
                    continue;
                if(Graph[j][k] > Graph[j][i] + Graph[i][k]){
                    Graph[j][k] = Graph[j][i] + Graph[i][k];
                    vector<int> reset(0, 0);
                    path[j][k] = reset;
                    for(int l = 0; l < path[j][i].size(); l++)
                        path[j][k].push_back(path[j][i][l]);
                    for(int l = 1; l < path[i][k].size(); l++)
                        path[j][k].push_back(path[i][k][l]);
                }
            }
        }
    }
}
int main(void){
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
    int n, m;
    for(int i = 0; i < 101; i++){
        for(int j = 0; j < 101; j++){
            Graph[i][j] = INF;
        }
    }
    cin >> n;
    cin >> m;
    for(int i = 0; i < m; i++){
        int a, b, c;
        cin >> a >> b >> c;
        if(Graph[a][b] > c){
            Graph[a][b] = c;
            path[a][b].clear();
            path[a][b].push_back(a);
            path[a][b].push_back(b);
        }
    }
    floyd(n);
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(Graph[i][j] == INF)
                Graph[i][j] = 0;
            cout << Graph[i][j] << " ";
        }
        cout << "\n";
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(Graph[i][j] == 0){
                cout << "0\n";
                continue;
            }
            cout << path[i][j].size()<< " ";
            for(int k = 0; k < path[i][j].size(); k++)
                cout << path[i][j][k] << " ";
            cout << "\n";
        }
    }
}