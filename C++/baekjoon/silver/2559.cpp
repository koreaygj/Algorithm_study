#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main(void)
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
    int n, k;
    cin >> n >> k;
    vector<int> arr(n + 1, 0);
    for(int i = 1; i <= n; i++)
    {
        cin >> arr[i];
        arr[i] += arr[i - 1];
    }
    int ans = -987654321;
    for(int i = k; i <= n; i++)
    {
        ans = max(ans, arr[i] - arr[i - k]);
    }
    cout << ans << "\n";
}