#include <bits/stdc++.h>
using namespace std;
int main(void){
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
    int N;
    vector<int> arr(4000001, 0);
    vector<int> decimal;
    cin >> N;
    for(int i = 2; i <= sqrt(N); i++){
        if(arr[i] == 1)
            continue;
        for(int j = i + i; j <= N; j += i){
            arr[j] = 1;
        }
    }
    for(int i = 2; i <= N; i++){
        if(!arr[i])
            decimal.push_back(i);
    }
    int st = 0;
    int end = 0;
    int sum = 2;
    int answer = 0;
    while(end < decimal.size() && st <= end){
        if(sum > N){
            sum -= decimal[st++];
        }
        else{
            sum += decimal[++end];
        }
        if(sum == N){
            sum -= decimal[st++];
            answer++;
        }
    }
    cout << answer << "\n";
}