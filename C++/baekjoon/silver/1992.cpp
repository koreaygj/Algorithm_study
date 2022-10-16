#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector<vector<int>> board(64, vector<int>(64, 0));
string solution(int st_x, int st_y, int size){ 
    int color = board[st_x][st_y];
    int quad = size / 2;
    string ans = "";
    for(int i = st_x; i < st_x + size; i++){
        for(int j = st_y; j < st_y + size ;j++){
            if(board[i][j] != color){
                ans += solution(st_x, st_y, quad);
                ans += solution(st_x, st_y + quad, quad);
                ans += solution(st_x + quad, st_y, quad);
                ans += solution(st_x + quad, st_y + quad, quad);
                return "(" + ans + ")";
            }
        }
    }
    if(color == 1)
        return "1";
    else
        return "0";
}
int main(void){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    for(int i = 0; i < n ;i++){
        string tmp; 
        cin >> tmp;
        for(int j = 0; j < n; j++)
            board[i][j] = tmp[j] - '0';
    }
    cout <<solution(0, 0, n) + "\n";
}