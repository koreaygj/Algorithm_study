#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int solution(vector<long long int> arr){
    vector<long long int> ans;
    for(int i = 0; i < arr.size(); i++){
        if(ans.empty()){
            ans.push_back(arr[i]);
            continue;
        }
        if(ans.back() < arr[i]){
            ans.push_back(arr[i]);
        }
        else{
            int left = 0;
            int right = ans.size();
            while(left < right){
                int mid = (left + right) / 2;
                if(ans[mid] < arr[i]){
                    left = mid + 1;
                }
                else{
                    right = mid;
                }
            }
            ans[right] = arr[i];
        }
    }
    return ans.size();
}
int main(void){
    int n;
    cin >> n;
    vector<long long int> arr(n, 0);
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    cout << solution(arr) << "\n";
}