#include<bits/stdc++.h>
using namespace std;
#define INF 987654321
int main(void){
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
    int v, e;
    int board[401][401];
    cin >> v >> e;
    for(int i = 0; i < 401; i++){
        for(int j = 0; j < 401; j++)
            board[i][j] = INF;
    }
    for(int i = 0; i < e; i++){
        int a, b, c;
        cin >> a >> b >> c;
        board[a][b] = c;
    }
    for(int i = 1; i <= v; i++){
        for(int j = 1; j <= v; j++){
            for(int k = 1; k <= v; k++){
                if(j == k)
                    continue;
                board[j][k] = min(board[j][k], board[j][i] + board[i][k]);
            }
        }
    }
    int answer = INF;
    for(int i = 1; i <= v; i++){
        for(int j = i + 1; j <= v; j++){
            if(board[i][j] != INF && board[j][i] != INF)
                answer = min(answer, board[i][j] + board[j][i]);
        }
    }
    if(answer == INF)
        answer = -1;
    cout << answer << "\n";
}