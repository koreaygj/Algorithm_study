#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
vector<vector<int>> map(26, vector<int> (26, 0));
vector<vector<int>> memo(26, vector<int> (26, 0));
int answer, complex_num, n;
class point
{
    public:
    int x;
    int y;
};
void solution(int x, int y)
{
    vector<point> cardinal_point = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
    complex_num++;
    memo[x][y] = 1;
    for(int i = 0; i < 4; i++) 
    {
        int n_x, n_y;
        n_x = x + cardinal_point[i].x;
        n_y = y + cardinal_point[i].y;
        if(n_x < 0 || n_y < 0 || n_x > n || n_y > n)
            continue;
        if(map[n_x][n_y] == 1 && memo[n_x][n_y] == 0)
            solution(n_x, n_y);
    }
    return;
}
int main(void)
{
    vector<int> complex;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        string line;
        cin >> line;
        for(int j = 0; j < n; j++)
        {
            map[i][j] = int(line[j]) - '0';
        }
    }
    for(int i = 0 ; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(map[i][j] == 1 && memo[i][j] == 0)
            {
                complex.push_back(complex_num);
                complex_num = 0;
                answer++;
                solution(i, j);
            }  
        }
    }
    cout << answer << "\n";
    complex.push_back(complex_num);
    sort(complex.begin(), complex.end());
    for(int i = 1; i < complex.size(); i++)
    {
        cout << complex[i] << "\n";
    }
}