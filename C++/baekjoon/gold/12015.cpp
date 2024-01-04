#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int solution(vector<int> arr){
    vector<int> ans;
    ans.push_back(0);
    for(int i = 0; i < arr.size(); i++){
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
    return ans.size() - 1;
}
int main(void){
    int n;
    cin >> n;
    vector<int> arr(n, 0);
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    cout << solution(arr) << "\n";
}