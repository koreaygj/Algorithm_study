#include <iostream>
#include <algorithm>
using namespace std;
int main(void)
{
    int n, k;
    cin >> n >> k;
    int count = 0;
    while(n >= count)
    {
        count++;
        if(n % count == 0)
        {
            k--;
            if(k == 0)
            {
                cout << count << "\n";
                return 0;
            }
        }
    }
    cout << 0 << "\n";
}