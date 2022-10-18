#include <iostream>
#include <algorithm>
#include <vector>
#define mod 1000000007
using namespace std;
long long int solution(long long int a, long long int b){ 
    if(b == 1)
        return a % mod;
    long long int tmp = solution(a, b / 2);
    if(b % 2 == 0)
        return (tmp * tmp) % mod;
    else
        return (((tmp * tmp) % mod) * a) % mod;
}
int main(void){
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
    int n, k;
    cin >> n >> k;
    vector<long long int> memo(4000001, 0);
    memo[0] = 1;
    for(int i = 1; i <= n; i++){
        memo[i] = (memo[i - 1] * i) % mod;
    }
    if(n == k || !k){
        cout << "1\n";
        return 0;
    }
    long long int temp = (memo[k] * memo[n - k]) % mod;
    long long int answer = (memo[n] * solution(temp, mod - 2)) % mod; 
    cout << answer << "\n";
    return 0;
}