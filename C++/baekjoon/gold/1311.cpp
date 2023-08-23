#include <iostream>
using namespace std;
int N;
int DP[20][1 << 20];
int Cost[21][21];
int dfs(int index, int mask){
    if(index == N )
        return 0;
    if(DP[index][mask] != -1)
        return DP[index][mask];
    int& tmp = DP[index][mask];
    tmp = 987654321;
    for(int i = 0; i < N; i++){
        if((mask & (1 << i)) != 0)
            continue;
        tmp = min(tmp, Cost[i][index] + dfs(index + 1,( mask | (1 << i))));
    }
    return tmp;
}
int main(void){
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
    cin >> N;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++)
             cin >> Cost[i][j];
    }
    memset(DP, -1, sizeof(DP));
    cout << dfs(0, 0) << "\n";
    return 0;
}