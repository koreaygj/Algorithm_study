#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
class point{
    public:
    int y;
    int x;
};
class map{
    public:
    point red;
    point blue;
    int count;
};
vector<string> board(10, "");
vector<point> cardinal = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
int n, m;
point tilt(point ball, int i)
{
    while(1)
    {
        if(board[ball.y][ball.x] != '#' && board[ball.y][ball.x] != 'O')
        {
            ball.y += cardinal[i].y;
            ball.x += cardinal[i].x;
        }
        else
        {
            if(board[ball.y][ball.x] == '#')
            {
                ball.y -= cardinal[i].y;
                ball.x -= cardinal[i].x;
            }
            cout << i << endl;
            cout << ball.y << "         " << ball.x << endl;
            cout << board[ball.y][ball.x] << endl;
            return ball;
        }
    }
}
int bfs(point red, point blue)
{
    int visit[10][10][10][10] = {0,};
    int answer = -1;
    queue<map> path;
    path.push({red, blue, 0});
    visit[red.y][red.x][blue.y][blue.x] = 1;
    while(!path.empty())
    {
        point cur_red, cur_blue;
        cur_red = path.front().red;
        cur_blue = path.front().blue;
        int count = path.front().count;
        path.pop();
        if(count > 10)
            break;
        if(board[cur_red.y][cur_red.x] == 'O' && board[cur_blue.y][cur_blue.x] != 'O')
        {
            answer = count;
            break;
        }
        for(int i = 0; i < 4; i++)
        {
            point next_red, next_blue;
            next_red = cur_red;
            next_blue = cur_blue;
            cout << "RED" << endl;
            next_red = tilt(next_red, i);
            cout << "BLUE" << endl;
            next_blue = tilt(next_blue, i);
            if(next_red.y == next_blue.y && next_red.x == next_blue.x)
            {
                if(board[next_red.y][next_red.x] != 'O')
                {
                    int red_dist = abs(next_red.y - cur_red.y) + abs(next_red.x - cur_red.x);
                    int blue_dist = abs(next_blue.y - cur_blue.y) + abs(next_blue.x - cur_blue.x);
                    if(red_dist > blue_dist)
                    {
                        next_red.y -= cardinal[i].y;
                        next_red.x -= cardinal[i].x;
                    }
                    else
                    {
                        next_blue.y -= cardinal[i].y;
                        next_blue.x -= cardinal[i].x;
                    }
                }
            }
            if(visit[next_red.y][next_red.x][next_blue.y][next_blue.x] == 0)
            {
                visit[next_red.y][next_red.x][next_blue.y][next_blue.x] = 1;
                if(next_blue.x == 11)
                {
                    cout << "check";
                }
                cout << next_red.y << " " << next_red.x << endl;
                cout << next_blue.y << " " << next_blue.x << endl;
                cout << count + 1 << endl;
                path.push({next_red, next_blue, count+1});
            }
        }
    }
    return answer;
}
int main(void){
    cin.tie(NULL);
    cout.tie(NULL);
    point red, blue;
    cin >> n >> m;
    for(int i = 0; i < n; i++)
    {
        cin >> board[i];
        for(int j = 0; j < m; j++)
        {
            if(board[i][j] == 'R')
                red = {i, j};
            if(board[i][j] == 'B')
                blue = {i, j};
        }
    }
    cout << bfs(red, blue) << "\n";
}