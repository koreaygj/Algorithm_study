#include <bits/stdc++.h>
using namespace std;
long long int ans[10];
void cal(long long int a, long long int cnt){
    while(a > 0){
        ans[a % 10] += cnt;
        a /= 10;
    }
}
void solution(long long int st, long long int end, long long int cnt){
    while(st % 10 != 0 && st <= end){
        cal(st, cnt);
        st++;
    }
    if(st > end)
        return;
    while(end % 10 != 9 && st <= end){
        cal(end, cnt);
        end--;
    }
    st /= 10;
    end /= 10;
    for(int i = 0; i < 10; ++i)
        ans[i] += (end - st + 1) * cnt;
    solution(st, end, cnt * 10);
}
int main(void){
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
    long long int N;
    cin >> N;
    long long int st = 1;
    long long int cnt = 1;
    solution(st, N, cnt);
    for(int ans : ans){
        cout << ans << " ";
    }
    cout << "\n";
}