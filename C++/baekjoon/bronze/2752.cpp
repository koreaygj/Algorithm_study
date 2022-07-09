#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main(void)
{
    vector<int> arr(3, 0);
    cin >> arr[0] >> arr[1] >> arr[2];
    sort(arr.begin(), arr.end());
    cout << arr[0] << " " << arr[1] << " " << arr[2];
}