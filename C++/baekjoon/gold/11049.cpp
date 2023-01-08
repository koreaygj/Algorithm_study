#include <iostream>
#include <algorithm>
using namespace std;
const int INF = 987654321;
int memo[501][501];
pair<int, int> matrix[501];
int MAT_sum(pair<int, int> a, pair<int, int> b){
    return a.first * b.first * b.second;
}
pair<int, int> dp(int a, int b){
    if(a == b)
        return matrix[a];
    if(memo[a][b] != 0){
        return pair<int, int> (matrix[a].first, matrix[b].second);
    }
    memo[a][b] = INF;
    for(int i = a; i < b; i++){
        memo[a][b] = min(memo[a][b], MAT_sum(dp(a, i), dp(i + 1, b)) +  memo[a][i] + memo[i + 1][b]);
    }
    return pair<int, int> (matrix[a].first, matrix[b].second);
}
int solution(int n){
    int answer = INF;
    if(n == 1)
        return 0;
    for(int i = 0; i < n - 1; i++){
        answer = min(answer, MAT_sum(dp(0, i), dp(i + 1, n - 1)) + memo[0][i] + memo[i + 1][n - 1]);
    }
    return answer;
}
int main(void){

    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> matrix[i].first >> matrix[i].second;
    }
    cout << solution(n) << "\n";
}