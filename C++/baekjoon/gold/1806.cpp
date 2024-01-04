#include <bits/stdc++.h>
#define INF INT_MAX
using namespace std;
int main(void){
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
    int n, s;
    int arr[100001];
    cin >> n >> s;
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    int st = 0;
    int end = 0;
    int sum = arr[0];
    int answer = INF;
    while(end < n && st <= end){
        if(sum >= s){
            answer = min(answer, end - st + 1);
            sum -= arr[st++];
        }
        else{
            sum += arr[++end];
        }
    }
    if(answer == INF){
        cout << "0\n";
        return 0;
    }
    cout << answer << "\n";
    return 0;
}