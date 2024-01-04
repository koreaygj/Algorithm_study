#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
int n, m;
vector<vector<int>> map(1005, vector<int> (1005, 0));
vector<vector<int>> visit(1005, vector<int> (1005, 0));
class point
{
    public:
    int y;
    int x;
};
queue<point> tomato;
void bfs()
{
    vector<point> cardinal_point = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
    while(!tomato.empty())
    {
        int st_y = tomato.front().y;
        int st_x = tomato.front().x;
        tomato.pop();
        for(int i = 0;i < 4; i++)
        {
            int n_y = st_y + cardinal_point[i].y;
            int n_x = st_x + cardinal_point[i].x;
            if( n_y < 0 || n_x < 0 || n_y > m - 1 || n_x > n - 1)
                continue;
            if(map[n_y][n_x] == 0 && visit[n_y][n_x] == 0)
            {
                map[n_y][n_x] = map[st_y][st_x] + 1;
                visit[n_y][n_x] = 1;
                tomato.push({n_y, n_x});
            }
        }
        for(int i = 0;i < m; i++)
        {
        for(int j = 0; j < n; j++)
            cout << map[i][j] << " ";
        cout << endl;
        }
        cout << endl;
    }
}
int check()
{
    int answer = 0;
    for(int i = 0;i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(map[i][j] == 0)
                return -1;
            else if(map[i][j] == -1)
                continue;
            else if(answer < map[i][j])
                answer = map[i][j];
        }
    }
    if(answer == 1)
        return 0;
    return answer - 1;
}
void solution()
{
    for(int i = 0;i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(map[i][j] == 1)
            {
                tomato.push({i, j});
                visit[i][j] = 1;
            }
        }
    }
    bfs();
    cout << check() << "\n";
}
int main(void)
{
    cin >> n >> m;
    int check = 0;
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin >> map[i][j];
            if(map[i][j] == 0)
                check++;
        }
    }
    solution();
}