#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int solution(vector<long long int> array, int m){
    long long int min = 1;
    long long int max = array.back();
    int answer;
    while(min <= max){
        long long int mid = (min + max) / 2;
        long long tmp = 0;
        for(int arr: array){
            tmp += (arr - mid) >= 0 ? (arr - mid) : 0;
        }
        if(tmp >= m){
            min = mid + 1;
            answer = mid;
        }
        else{
            max = mid - 1;
            answer = mid - 1;
        }
    }
    return answer;
}
int main(void){
    int n, m;
    cin >> n >> m;
    vector<long long int> input(n, 0);
    for(int i = 0; i < n; i++)
        cin >> input[i];
    sort(input.begin(), input.end());
    cout << solution(input, m) << "\n";
}