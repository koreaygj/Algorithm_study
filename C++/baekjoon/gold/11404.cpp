#include<bits/stdc++.h>
using namespace std;
#define INF 987654321
int main(void){
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
    int n, m;
    int board[101][101];
    cin >> n;
    cin >> m;
    for(int i = 0; i < 101; i++){
        for(int j = 0; j < 101; j++){
            board[i][j] = INF;
        }
    }
    for(int i = 0; i < m; i++){
        int a, b, c;
        cin >> a >> b >> c;
        board[a][b] = min(c, board[a][b]);
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            for(int k = 1; k <= n; k++){
                if(j == k)
                    continue;
                board[j][k] = min(board[j][k], board[j][i] + board[i][k]);
            }
        }
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(board[i][j] == INF)
                board[i][j] = 0;
            cout << board[i][j] << " ";
        }
        cout << "\n";
    }
}