#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int n, m;
vector<vector<int>> memo(55, vector<int> (55, 0));
class point{
    public:
    int y;
    int x;
};
int bfs(int point_y, int point_x, int height,  vector<vector<int>> land)
{
    queue<point> block;
    vector<point> cardinal_point = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
    int count = 1;
    bool check = false;
    block.push({point_y, point_x});
    while(!block.empty())
    {
        int st_y = block.front().y;
        int st_x = block.front().x;
        block.pop();
        for(int i = 0; i < 4; i++)
        {
            int next_y = st_y + cardinal_point[i].y;
            int next_x = st_x + cardinal_point[i].x;
            if(next_y < 0 || next_x < 0 || next_y > n - 1 || next_x > m - 1)
            {
                check = true;
                continue;
            }
            if(memo[next_y][next_x] == 1)
                continue;
            if(land[next_y][next_x] < height)
            {
                block.push({next_y, next_x});
                memo[next_y][next_x] = 1;
                count++;
            }
        }
    }
    if(check)
        return 0;
    return count;
}
int find(int height, vector<vector<int>> land)
{
    int ans = 0;
    vector<vector<int>> reset(55, vector<int>(55, 0));
    memo = reset;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(memo[i][j] == 1)
                continue;
            if(land[i][j] < height)
            {
                memo[i][j] = 1;
                ans += bfs(i, j, height, land);
            }
        }
    }
    return ans;
}
int main(void)
{
    cin >> n >> m;
    int height = 0;
    int answer = 0;
    vector<vector<int>> land(55, vector<int> (55, 0));
    for(int i = 0; i < n; i++)
    {
        string st;
        cin >> st;
        for(int j = 0; j < st.size(); j++)
        {
            land[i][j] = (int)st[j] - '0';
            height = max(height, land[i][j]);
        }
    }
    for(int i = 1; i <= height; i++)
        answer += find(i, land);
    cout << answer << "\n";
}