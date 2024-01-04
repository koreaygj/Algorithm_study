#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main(void)
{
    while(1)
    {
        vector<int> arr(3, 0);
        for(int i = 0; i < 3; i++)
            cin >> arr[i];
        if(arr[0] == 0 && arr[1] == 0 && arr[2] == 0)
              return 0;
        sort(arr.begin(), arr.end());
        if(arr[2] * arr[2] == arr[1] * arr[1] + arr[0] * arr[0])
            cout << "right\n";
        else
            cout << "wrong\n";
    }
}