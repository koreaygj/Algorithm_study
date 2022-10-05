#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int solution(long long int n, long long int k){
    long long int left = 1;
    long long int right = k;
    long long int ans = 0;
    while(left <= right){
        long long int tmp = 0;
        long long int mid = (left + right) / 2;
        for(int i = 1; i <= n; i++){
            tmp += min(mid / i , n);
        }
        if(tmp == k)
        {
            ans = mid;
            right = mid - 1;
        }
        else if(tmp < k)
            left = mid + 1;
        else
        {
            ans = mid;
            right = mid - 1;
        }
    } 
    return ans;
}
int main(void){
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
    long long int n, k;
    cin >> n;
    cin >> k;
    cout << solution(n, k) << "\n";
}