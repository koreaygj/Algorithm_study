#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int n, m;
vector<vector<int>> memo(55, vector<int> (55, 0));
int bfs(vector<vector<int>> land, int current_y, int current_x, int max_block)
{
    queue<pair<int, int>> point;
    vector<pair<int, int>> cardinal_point = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
    vector<vector<int>> reset(55, vector<int>(55, 0));
    point.push({current_y, current_x});
    int count = 1;
    int result = land[current_y][current_x];
    int check_pool = 0;
    memo[current_y][current_x] = 1;
    cout << "start: " << current_x << " " << current_y << endl;
    while(!point.empty())
    {
        pair<int, int> current = point.front();
        point.pop();
        cout << current.first << " " << current.second << endl;
        for(int i = 0; i < 4; i++)
        {
            int y = current.first + cardinal_point[i].first;
            int x = current.second + cardinal_point[i].second;
            if(y < 0 || y > n - 1 || x < 0 || x > m - 1)
            {
                check_pool = 1;
                continue;
            }
            if(memo[y][x] == 1)
                continue;
            if(max_block > land[y][x])
            {
                //cout << y << " " <<  x << endl;
                count++;
                result += land[y][x];
                point.push({y, x});
                memo[y][x] = 1;
            }
        }
    }
    if(check_pool == 1)
    {
        memo = reset;
        return 0;
    }
    cout << count << " " << max_block << " " << result << endl;
    return count * max_block - result;
}
int find(vector<vector<int>> land, int max_block)
{
    int answer = 0;
    vector<pair<int, int>> cardinal_point = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
    for(int k = max_block; k > 0; k--)
    {
        cout << "max: " << k << endl;
        for(int i = 1; i < n - 1; i++)
        {
            for(int j = 1; j < m - 1; j++)
            {
                if(memo[i][j] == 1)
                    continue;
                if(land[i][j] < k)
                {
                    memo[i][j] = 1;
                    answer += bfs(land, i, j, k);    
                }
            }
        }
    }
    return answer;
}
int main(void)
{
    cin >> n >> m;
    vector<vector<int>> land(55, vector<int> (55, 0));
    int max_block = 0;
    for(int i = 0; i < n; i++)
    {
        string st;
        cin >> st;
        for(int j = 0; j < st.size(); j++)
        {
            land[i][j] = (int)st[j] - '0';
            max_block = max(max_block, land[i][j]);
        }
    }
    cout << find(land, max_block) << "\n";
}