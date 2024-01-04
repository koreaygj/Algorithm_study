#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector<vector<int>> board(2187, vector<int>(2187, 0));
int one, zero, n_one;
void solution(int st_x, int st_y, int size){ 
    int color = board[st_x][st_y];
    int oct = size / 3;
    string ans = "";
    for(int i = st_x; i < st_x + size; i++){
        for(int j = st_y; j < st_y + size ;j++){
            if(board[i][j] != color){
                solution(st_x, st_y, oct);
                solution(st_x, st_y + oct, oct);
                solution(st_x, st_y + oct + oct, oct);
                solution(st_x + oct, st_y, oct);
                solution(st_x + oct, st_y + oct, oct);
                solution(st_x + oct, st_y + oct + oct, oct);
                solution(st_x + oct + oct, st_y, oct);
                solution(st_x + oct + oct, st_y + oct, oct);
                solution(st_x + oct + oct, st_y + oct + oct, oct);
                return;
            }
        }
    }
    if(color == 1)
        one++;
    else if(color == -1)
        n_one++;
    else
        zero++;
}
int main(void){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    for(int i = 0; i < n ;i++){
        for(int j = 0; j < n; j++)
            cin >> board[i][j];
    }
    solution(0, 0, n);
    cout << n_one << "\n";
    cout << zero << "\n";
    cout << one << "\n";
}