#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
class point{
    public:
    int y;
    int x;
};
int n;
vector<vector<string>> grid(105, vector<string>(105, ""));
vector<vector<int>> visit(105, vector<int> (105, 0));
void bfs(string color, int y, int x)
{
    queue<point> area;
    vector<point> cardinal = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
    area.push({y, x});
    visit[y][x] = 1;
    while(!area.empty())
    {
        point current = area.front();
        area.pop();
        for(int i = 0; i < 4; i++)
        {
            int n_y = current.y + cardinal[i].y;
            int n_x = current.x + cardinal[i].x;
            if(n_y < 0 || n_x < 0 || n_y >= n || n_x >= n)
                continue;
            if(grid[n_y][n_x] == color && visit[n_y][n_x] == 0)
            {
                area.push({n_y, n_x});
                visit[n_y][n_x] = 1;
            }
        }
    }
}
int main(void)
{
    int normal = 0;
    int color_blind = 0;
    vector<vector<int>> reset(105, vector<int> (105, 0));
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        string input;
        cin >> input;
        for(int j = 0; j < n; j++)
            grid[i][j] = input[j];
    }
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(visit[i][j] == 1)
                continue;
            if(grid[i][j] == "R")
                bfs("R", i, j);
            else if(grid[i][j] == "G")
                bfs("G", i, j);
            else if(grid[i][j] == "B")
                bfs("B", i, j);
            normal++;
        }
    }
    visit = reset;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(grid[i][j] == "G")
                grid[i][j] = "R";
        }
    }
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(visit[i][j] == 1)
                continue;
            if(grid[i][j] == "R")
                bfs("R", i, j);
            else if(grid[i][j] == "B")
                bfs("B", i, j);
            color_blind++;
        }
    }
    cout << normal << " " << color_blind << "\n";
}