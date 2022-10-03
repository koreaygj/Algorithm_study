#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int solution(vector<long long int> array, int n)
{
    long long int max = array.back();
    long long int min = 1;
    long long int answer = 0;
    while(min <= max){
        answer = 0;
        long long int mid = (min + max) / 2;
        for(int arr : array){
            answer += arr / mid;
        }
        if(answer >= n)
        {
            min = mid + 1;
            answer = mid;
        }
        else{
            max = mid -1;
            answer = mid - 1;
        }
    }
    return answer;
}
int main(void){
    int k, n;
    cin >> k >> n;
    vector<long long int> input(k, 0);
    for(int i = 0; i < k ; i++)
        cin >> input[i];
    sort(input.begin(), input.end());
    cout << solution(input, n) << "\n";
}