#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
long long int solution(vector<long long int> home, long long int c){
    long long int left = 0;
    long long int right = home.back();
    long long int answer = -1;
    while(left <= right){
        long long int st = home[0];
        long long int mid = (left + right) / 2;
        long long int count = 1;
        for(long long int i = 0; i < home.size(); i++){
            if(home[i] - st >= mid){
                count++;
                st = home[i];
            }
        }
        if(count >= c){
            answer = max(answer, mid);
            left = mid + 1;
        }
        else{
            right = mid - 1;
        }
    }
    return answer;
}
int main(void){
    int n, c;
    cin >> n >> c;
    vector<long long int> home(n, 0);
    for(long long int i = 0; i < n; i++)
        cin >> home[i];
    sort(home.begin(), home.end());
    cout << solution(home, c) << "\n";
}