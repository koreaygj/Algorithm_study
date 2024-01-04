#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
vector<vector<int>> lab(10, vector<int> (10, 0));
vector<vector<int>> simul(10, vector<int> (10, 0));
int answer;
int n, m;
void print(vector<vector<int>> a)
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        cout << a[i][j] << " ";
        cout << endl;
    }
    cout << endl;
}
class point
{
    public:
    int x;
    int y;
};
void bfs(int x,int y, vector<vector<int>> visit)
{
    queue<point> virus;
    virus.push({x, y});
    visit[x][y] = 1;
    vector<point> cardinal = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
    while(!virus.empty())
    {
        int i_x = virus.front().x;
        int i_y = virus.front().y;
        virus.pop();
        for(int i = 0;i < 4; i++)
        {
            int n_x = i_x + cardinal[i].x;
            int n_y = i_y + cardinal[i].y;
            if(n_x < 0 || n_y < 0 || n_x >= n || n_y >= m || simul[n_x][n_y] == 1)
                continue;
            if(simul[n_x][n_y] == 0 && visit[n_x][n_y] == 0)
            {
                simul[n_x][n_y] = 2;
                visit[n_x][n_y] = 1;
                virus.push({n_x, n_y});
            }
        }
    }
}
void solution()
{
    int ans = 0;
    vector<vector<int>> visit(10, vector<int> (10, 0));
    simul = lab;
    for(int i = 0;i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(simul[i][j] == 2 && visit[i][j] == 0)
                bfs(i, j, visit);
        }
    }
    for(int i = 0;i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(simul[i][j] == 0)
                ans++;
        }
    }
    if(answer < ans)
    {
        print(simul);
        answer = ans;
    }
    return;
}
void wall(int count, int x, int y)
{
    if(count == 3)
    {
        solution();
        return;
    }
    for(int i = x; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(i == x && j < y)
                continue;
            if(lab[i][j] == 0)
            {
            lab[i][j] = 1;
            wall(count + 1, i, j);
            lab[i][j] = 0;
            }
        }
    }
}
int main(void)
{
    cin >> n >> m;
    for(int i = 0;i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            cin >> lab[i][j];
        }
    }
    wall(0, 0, 0);
    cout << answer << "\n";
}