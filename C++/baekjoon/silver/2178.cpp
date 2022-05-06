#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
int n, m, move_count, layer;
vector<vector<int>> maze(101, vector<int>(101, 0));
vector<vector<int>> memo(101, vector<int>(101, 0));
vector<int> result;
class point
{
    public:
    int x;
    int y;
};
void solution(int x, int y)
{
    queue<point> path;
    path.push({x, y});
    memo[x][y] = 0;
    vector<point> cardinal_point = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    vector<int> deep(100, 0);
    deep[0] = 1;
    while(!path.empty())
    {
        int init_x, init_y;
        init_x = path.front().x;
        init_y = path.front().y;
        cout << move_count << " " << init_x << "," << init_y << ": ";
        for(int i = 0; i < 15; i++)
            cout << deep[i] << " ";
        cout << endl;
        if(deep[move_count] == 0)
        {
            move_count++;
            layer++;
        }
        deep[layer]--;
        path.pop();
        for(int i = 0; i < 4; i++)
        {
            int n_x, n_y;
            n_x = init_x + cardinal_point[i].x;
            n_y = init_y + cardinal_point[i].y;
            if(n_x < 0 || n_y < 0 || n_x > n - 1 || n_y > m -1)
                continue;
            if(maze[n_x][n_y] == 1 && memo[n_x][n_y] == 0)
            {
                deep[layer+1]++;
                path.push({n_x, n_y});
                memo[n_x, n_y] = 1;
                if(n_x == n-1 && n_y == m-1)
                {
                    move_count++;
                    return;
                }
            }
        }
    }
}
int main(void)
{
    cin >> n >> m;
    for(int i = 0; i < n; i++)
    {
        string line;
        cin >> line;
        for(int j = 0; j < m; j++)
        {
            maze[i][j] = int(line[j]) - '0';
        }
    }
    solution(0, 0);
    cout << move_count + 1 << "\n";
}