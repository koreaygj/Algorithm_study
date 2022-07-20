#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main(void)
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<pair<int, int>> line(n, {0, 0});
    pair<int, int> result;
    int answer = 0;
    for(int i = 0; i < n; i++)
        cin >> line[i].first >> line[i].second;
    sort(line.begin(), line.end());
    result = line[0];
    for(int i = 1; i < n; i++)
    {
        int x = line[i].first;
        int y = line[i].second;
        if(result.second >= x )
            result.second = max(result.second, y);
        else
        {
            answer += result.second - result.first;
            result = line[i];
        }
    }
    answer += result.second - result.first;
    cout << answer << "\n";
}