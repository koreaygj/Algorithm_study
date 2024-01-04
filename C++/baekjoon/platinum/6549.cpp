#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;
vector<long long int> histogram(100005, 0);
long long int solution(int st, int end){
    int mid = (st + end) / 2;
    if(st == end)
        return histogram[st];
    long long int temp = max(solution(st, mid), solution(mid + 1, end));
    int left = mid;
    int right = mid;
    long long int width = 1;
    long long int height = histogram[mid];
    while(st <= left  && right <= end){
        long long int result_L, result_R;
        result_L = st < left ? min(histogram[left - 1], height) :  -1;
        result_R = right <= end ? min(histogram[right + 1], height) : -1;
        if(result_L <= result_R){
            height = result_R;
            right++;
        }
        else{
            height = result_L;
            left--;
        }
        temp = max(temp, ++width * height);
    }
    return temp;
}
int main(void){
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
    long long int n = 1;
    while(n != 0){
        cin >> n;
        if(n == 0)
            break;
        for(int i = 0; i < n; i++){
            cin >> histogram[i];
        }
        cout << solution(0, n - 1) << "\n";
        vector<long long int> reset(100005, 0);
        histogram = reset;
    }
    return 0;
}