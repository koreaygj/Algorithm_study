#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
class trunk
{
    public:
    int n_node;
    int weigth;
};
struct cmp{
  bool operator()(trunk a, trunk b){
      return a.weigth > b.weigth;
  }
};
vector<trunk> path[20005];
vector<int> dist(20005, 2147483647);
int v, e;
void solution(int k)
{
    dist[k] = 0;
    priority_queue<trunk, vector<trunk>, cmp> way;
    way.push({k, 0});
    while(!way.empty())
    {
        trunk st_trunk = way.top();
        int st_node = st_trunk.n_node;
        int st_weigth = st_trunk.weigth;
        way.pop();
        if(st_weigth > dist[st_node])
            continue;
        for(int i = 0;i < path[st_node].size(); ++i)
        {
            int n_node = path[st_node][i].n_node;
            int n_weigth = path[st_node][i].weigth;
            if (st_weigth + n_weigth < dist[n_node])
            {
                dist[n_node] = st_weigth + n_weigth;
                way.push({n_node, dist[n_node]});
            }
        }
    }
    return;
}
int main(void)
{
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    int k;
    cin >> v >> e;
    cin >> k;
    for(int i = 0; i < e; i++)
    {
        int st_node, n_node, weigth;
        cin >> st_node >> n_node >> weigth;
        path[st_node].push_back({n_node, weigth});
    }
    solution(k);
    for(int i = 1; i <= v; i++)
    {
        if(dist[i] == 2147483647)
        {
            cout << "INF\n";
            continue;
        }
        cout << dist[i] << "\n";
    }
}