#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int n, m, v;
vector<int> graph[1005];
vector<int> visit(1005, 0);
void dfs(int input)
{
    visit[input] = 1;
    cout << input << " ";
    for(int i = 0; i < graph[input].size(); i++)
    {
        int n_node;
        n_node = graph[input][i];
        if(visit[n_node] != 1)
        {
            visit[n_node] = 1;
            dfs(n_node);
        }
    }
}
void bfs(int input)
{
    queue<int> node;
    node.push(input);
    visit[input] = 1;
    while(!node.empty())
    {
        cout << node.front() << " ";
        int s_node = node.front();
        node.pop();
        for(int i = 0;i < graph[s_node].size(); i++)
        {
            int n_node = graph[s_node][i];
            if(visit[n_node] != 1)
            {
                visit[n_node] = 1;
                node.push(n_node);
            }
        }
    }
}
int main(void)
{
    cin >> n >> m >> v;
    for(int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    for(int i = 1 ;i <= n ;i++)
    {
        sort(graph[i].begin(), graph[i].end());
    }
    dfs(v);
    cout << endl;
    vector<int> reset(1005, 0);
    visit = reset;
    bfs(v);
}