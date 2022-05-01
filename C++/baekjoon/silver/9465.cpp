#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int solution(vector<vector<int>> score, int n)
{
    if(n == 1)
        return max(score[0][n], score[1][n]);
    else
    {
        score[0][2] += score[1][1];
        score[1][2] += score[0][1];
        for(int i = 3; i <= n; i++)
        {
            score[0][i] += max(score[1][i-1], score[1][i-2]);
            score[1][i] += max(score[0][i-1], score[0][i-2]);
        }
    }
    return max(score[0][n], score[1][n]);
}
int main(void)
{
    int t;
    cin >> t;
    for(int i = 0;i < t; i++)
    {
        int n;
        cin >> n;
        vector<vector<int>> sticker(2, vector<int> (n+1, 0));
        for(int j = 1; j <= n; j++)
            cin >> sticker[0][j];
        for(int j = 1; j <= n; j++)
            cin >> sticker[1][j];
        cout << solution(sticker, n) <<"\n";
    }
}