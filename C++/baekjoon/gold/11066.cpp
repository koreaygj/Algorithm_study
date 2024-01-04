#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
const int INF = 987654321;    
int memo[501][501];
int file[501];
int p_sum[501];
int dp(int a, int b){
    if(a == b)
        return file[a];
    if(memo[a][b] != -1)
        return memo[a][b];
    int sum = a - 1 < 0 ? p_sum[b] : p_sum[b] - p_sum[a - 1];
    memo[a][b] = INF;
    for(int i = a; i < b; i++)
    {
        memo[a][b] = min(memo[a][b], dp(a, i) + dp(i + 1, b) + sum);
    }
    return memo[a][b];
}
void solution(int n){
    int answer = INF;
    for(int i = 0; i < n - 1; i++){
        answer = min(answer, dp(0, i) + dp(i + 1, n -1));
    }
    cout << answer << "\n";
}
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    for(int i = 0; i < t; i++){
        int n;
        cin >> n;
        memset(memo, -1, sizeof(memo));
        for(int i = 0; i < n; i++){ 
            cin >> file[i];
            p_sum[i] = file[i];
            if(i > 0)
                p_sum[i] += p_sum[i - 1];
        }
        solution(n);
    }
}