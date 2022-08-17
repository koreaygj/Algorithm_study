#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(void){
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
    int n, m;
    long long int sum = 0;
    long long int answer = 0;
    cin >> n >> m;
    vector<long long int> remainder(m, 0);
    for(int i = 1; i <= n; i++)
    {
        long long int a;
        cin >> a;
        sum += a;
        remainder[sum % m]++;
        if(sum % m == 0)
            answer++;   
    }
    for(int i = 0; i < m ;i++)
    {
        if(remainder[i] < 2)
            continue;
        answer += remainder[i] * (remainder[i] - 1) / 2;
    }
    cout << answer << "\n";
}