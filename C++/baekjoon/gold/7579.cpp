#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
class app{
    public:
    int memory;
    int cost;
};
int main(void){
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
    int n, m;
    app a[101];
    int dp[101][10001] = {0, };
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        cin >> a[i].memory;
    for(int i = 1; i <= n; i++)
        cin >> a[i].cost;
    for(int i = 1; i <= n; i++){
        for(int j = 0; j <= 10000; j++){
            if(j - a[i].cost >= 0)
                dp[i][j] = max(dp[i][j], dp[i - 1][j - a[i].cost] + a[i].memory);
            dp[i][j] = max(dp[i][j], dp[i - 1][j]);
        }
    }
    for(int i = 0; i < 10001; i++){
        if(dp[n][i] >= m){
            cout << i << "\n";
            break;
        }
    }
}