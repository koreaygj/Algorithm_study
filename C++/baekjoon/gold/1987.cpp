#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class point{
    public:
    int y;
    int x;
};
vector<string> board(25, "");
vector<vector<int>> visit(25, vector<int>(25, 0));
vector<int> alphabet(26, 0);
int r, c;
int answer, cnt;
void dfs(int y, int x)
{
    vector<point> cardinal = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
    cnt++;
    answer = max(answer, cnt);
    for(int i = 0; i< 4;i++)
    {
        int n_y = y + cardinal[i].y;
        int n_x = x + cardinal[i].x;
        if(n_y < 0|| n_x < 0 || n_y >= r || n_x >= c || visit[n_y][n_x])
            continue;
        if(alphabet[board[n_y][n_x] - 'A'] != 0)
            continue;
        visit[n_y][n_x] = 1;
        alphabet[board[n_y][n_x] - 'A']++;
        dfs(n_y, n_x);
        visit[n_y][n_x] = 0;
        alphabet[board[n_y][n_x] - 'A']--;
        cnt--;
        }
    return;
}
int main(void){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin >> r >> c;
    for(int i = 0 ;i < r; i++)
    {
        cin >> board[i];
    }
    visit[0][0] = 1;
    alphabet[board[0][0] - 'A']++;
    dfs(0, 0);
    int cnt = 0;
    cout << answer << endl;
}