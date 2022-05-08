#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
int n;
int answer;
vector<vector<int>> graph(1005, vector<int>(1005, 0));
vector<vector<int>> visit(1005, vector<int>(1005, 0));
void dfs(int y)
{
    for(int i = 1; i <= n; i++)
    {
        if(graph[y][i] == 1 && visit[y][i] == 0 && visit[i][y] == 0)
        {
            visit[y][i] = 1;
            visit[i][y] = 1;
            dfs(i);
        }
    }
    return;
}
int solution()
{
    answer = 0;
    for(int i = 1;i <= n; i++)
    {
        if(graph[i][max_element(graph[i].begin(), graph[i].end()) - graph[i].begin()] == 0)
        {
            answer++;
            continue;
        }
        for(int j = 1; j <= n; j++)
        {
            if(graph[i][j] == 1 && visit[i][j] == 0 && visit[j][i] == 0)
            {
                answer++;
                visit[i][j] = 1;
                visit[j][i] = 1;
                dfs(j);
            }
        }
    }
    return answer;
}
int main(void)
{
    int m;
    cin >> n >> m;
    for(int i = 0; i < m ; i++)
    {
        int y, x;
        cin >> y >> x;
        graph[y][x] = 1;
        graph[x][y] = 1;
    }
    cout << solution() << "\n";
}