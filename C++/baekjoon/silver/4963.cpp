#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int w, h;        
vector<vector<int>> map(55, vector<int>(55, 0));
vector<vector<int>> visit(55, vector<int>(55, 0));
class point
{
    public:
    int y;
    int x;
};
void bfs(int st_y, int st_x)
{
    visit[st_y][st_x] = 1;
    queue<point> land;
    land.push({st_y, st_x});
    while(!land.empty())
    {
        int init_y = land.front().y;
        int init_x = land.front().x;
        land.pop();
        vector<point> cardinal = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}, {-1, -1}, {1, -1}, {1, 1}, {-1, 1}};
        for(int i = 0;i < 8; i++)
        {
            int n_y = init_y + cardinal[i].y;
            int n_x = init_x + cardinal[i].x;
            if(n_y < 0 || n_x < 0 || n_y > h || n_x > w)
                continue;
            if(map[n_y][n_x] == 1 && visit[n_y][n_x] == 0)
            {
                land.push({n_y, n_x});
                visit[n_y][n_x] = 1;
            }
        }
    }
}
int solution()
{
    int answer = 0;
    for(int i = 0; i < h; i++)
    {
        for(int j = 0; j < w; j++)
        {
            if(map[i][j] == 1 && visit[i][j] == 0)
            {
                bfs(i, j);
                answer++;
            }
        }
    }
    return answer;
}
int main(void)
{
    while(1){
        vector<vector<int>> reset(55, vector<int>(55, 0));
        map = reset;
        visit = reset;
        cin >> w >> h;
        if(w == 0 && h == 0)
            break;
        for(int i = 0; i < h; i++)
        {
            for(int j = 0; j < w; j++)
            cin >> map[i][j];
        }
        cout <<  solution() << "\n";
    }
}