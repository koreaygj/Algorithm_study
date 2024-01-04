#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
int n, k;
vector<int> map(100005, 0);
vector<int> visit(100005, 0);
void bfs(int n)
{
    queue<int> path;
    path.push(n);
    while(!path.empty())
    {
        int x = path.front();
        if(x == k)
            return;
        path.pop();
        vector<int> move = { x - 1, x + 1, x * 2};
        for(int i = 0;i < 3; i++)
        {
            int n_x = move[i];
            if(n_x < 0 || n_x > 100000 || visit[n_x] == 1)
                continue;
            if(map[n_x] != 0)
                map[n_x] = min(map[n_x] , map[x] + 1);
            else
                map[n_x] = map[x] + 1;
            visit[n_x] = 1;
            path.push(n_x);
        }
    }
}
int main(void)
{
    cin >> n >> k;
    bfs(n);
    cout << map[k] << "\n";
}