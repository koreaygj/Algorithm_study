#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector<vector<int>> board(128, vector<int>(128, 0));
int blue, white;
void solution(int st_x, int st_y, int size){ 
    int color = board[st_x][st_y];
    int quad = size / 2;
    for(int i = st_x; i < st_x + size; i++){
        for(int j = st_y; j < st_y + size ;j++){
            if(board[i][j] != color){
                solution(st_x, st_y, quad);
                solution(st_x, st_y + quad, quad);
                solution(st_x + quad, st_y, quad);
                solution(st_x + quad, st_y + quad, quad);
                return;
            }
        }
    }
    if(color == 1)
        blue++;
    else
        white++;
}
int main(void){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    for(int i = 0; i < n ;i++)
        for(int j = 0; j < n; j++)
            cin >> board[i][j];
    solution(0, 0, n);
    cout << white << "\n";
    cout << blue << "\n";
}