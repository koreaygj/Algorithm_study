#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, m, move_count;
vector<vector<int>> maze(101, vector<int>(101, 0));
vector<vector<int>> memo(101, vector<int>(101, 0));
vector<int> result;
class point
{
    public:
    int x;
    int y;
};
vector<point> path;
void solution(int x, int y)
{
    path.push_back({x, y});
    move_count++;
    if(x == n-1 && y == m-1)
    {
        result.push_back(move_count);
    }
    cout << x << " " << y << " " << move_count << endl;
    vector<point> cardinal_point = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    memo[x][y] = 1;
    for(int i = 0; i < 4; i++)
    {
        int n_x, n_y;
        n_x = x + cardinal_point[i].x;
        n_y = y + cardinal_point[i].y;
        if(n_x < 0 || n_y < 0 || n_x > n || n_y > m)
            continue;
        if(maze[n_x][n_y] == 1 && memo[n_x][n_y] == 0)
        {
            solution(n_x, n_y);
        }
    }
    move_count--;
    path.pop_back();
    return;
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
    cout << result[min_element(result.begin(), result.end()) - result.begin()] << "\n";
}