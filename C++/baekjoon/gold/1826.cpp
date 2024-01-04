#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
int main(void)
{
    int n;
    vector<pair<int, int>> oil;
    priority_queue<int, vector<int>, less<int>> que;
    int ans = 0;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        oil.push_back({a, b});
    }
    sort(oil.begin(), oil.end());
    int l, p;
    int idx = 0;
    cin >> l >> p;
    while(p < l)
    {
        while (oil[idx].first <= p && idx < n)
                   que.push(oil[idx++].second);
           
           if (!que.empty()) {
                   p += que.top();
                   que.pop();
                   ans++;
           }
           else if (idx == n || oil[idx].first > p) {
                   ans = -1;
                   break;
           }
    }
    cout << ans << "\n";
}