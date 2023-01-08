#include <iostream>
#include <algorithm>
using namespace std;
int N;
bool dp[31][15001];
void solution(int cnt, int w, int weight[]){
    if(cnt > N || dp[cnt][w])
        return;
    dp[cnt][w] = true;
    solution(cnt + 1, w, weight);
    solution(cnt + 1, w + weight[cnt], weight);
    solution(cnt + 1, abs(w - weight[cnt]), weight);
}
int main(void){
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
    int m;
    int weight[31] = {0};
    string answer = "";
    cin >> N;
    int sum;
    for(int i = 0; i < N; i++){
        cin >> weight[i];
    }
    solution(0, 0, weight);
    cin >> m;
    for(int i = 0; i < m; i++)
    {
        int ball;
        cin >> ball;
        if(ball > 15000){
            answer += "N ";
            continue;
        }
        answer += dp[N][ball] ? "Y ": "N ";
    }
    cout << answer << "\n";
}