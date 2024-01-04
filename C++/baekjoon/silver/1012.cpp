#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<vector<int>> field(55, vector<int> (55, 0));
vector<vector<int>> memo(55, vector<int> (55, 0));
int answer;
int m, n;
class point{
    public:
        int x;
        int y;
};
void print(vector<vector<int>> a, int m, int n)
{
    cout <<endl;
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
            cout << a[i][j] << " ";
        cout << endl;
    }
    cout << endl;
}
void solution(int x, int y)
{
    cout << x << " " << y << " " << answer << endl;
    vector<point> cardinal_point = {{0, -1}, {-1, 0}, {1, 0}, {0, 1}};
    memo[x][y] = 1;
    for(int i = 0; i < 4; i++)
    {
            int n_x, n_y;
            n_x = x + cardinal_point[i].x;
            n_y = y + cardinal_point[i].y;
            if(n_x < 0 || n_y < 0 || n_x > m || n_y > n)
                continue;
            if(field[n_x][n_y] == 1 && memo[n_x][n_y] == 0)
                solution(n_x, n_y);  
    }
    return;
}
int main(void)
{
    int T;
    cin >> T;
    for(int i = 0; i < T; i ++)
    {
        vector<vector<int>> reset(55, vector<int> (55, 0));
        answer = 0;
        field = reset;
        memo = reset;
        int k;
        cin >> m >> n >> k;
        for(int j = 0; j < k; j++)
        {
            int a, b;
            cin >> a >> b;
            field[a][b] = 1;
        }
        print(field, m, n);
        for(int h = 0; h < m; h++)
        {
            for(int g = 0; g < n; g++)
            {
                if(field[h][g] == 1 && memo[h][g] == 0)
                {
                    answer++;
                    solution(h, g);
                }
            }
        }
        cout << answer << "\n";
    }
}