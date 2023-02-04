#include <bits/stdc++.h>
using namespace std;
int N, C;
int Weigth[31];
void dfs(int st, int end, vector<long long int> &arr, long long int sum){
    if(st > end){
        arr.push_back(sum);
        return;
    }
    else{
        dfs(st + 1, end, arr, sum + Weigth[st]);
        dfs(st + 1, end, arr, sum);
    }
}
int main(void){
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
    cin >> N >> C;
    for(int i = 0; i < N; i++){
        cin >> Weigth[i];
    }
    vector<long long int> front;
    vector<long long int> back;
    long long int ans = 0;
    dfs(0, N / 2, front, 0);
    dfs(N / 2 + 1, N - 1, back, 0);
    sort(back.begin(), back.end());
    for(int i = 0; i < front.size(); i++){
        ans += upper_bound(back.begin(), back.end(), C - front[i]) - back.begin();
    }
    cout << ans << "\n";
}