#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(void)
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> table(n + 5, vector<int>(n + 5, 0));
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            long long int sum;
            cin >> sum;
            table[i][j] = sum + table[i][j - 1];
        }
    }
    for(int i = 0; i < m; i++)
    {
        long long int answer = 0;
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        for(int j = x1; j <= x2; j++)
        {
            answer += table[j][y2] - table[j][y1 - 1];
        }
        cout << answer << "\n";
    }
}