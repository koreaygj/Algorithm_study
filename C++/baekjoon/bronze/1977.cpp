#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
int main(void)
{
    int n, m;
    int sum = 0;
    int min = 10001;
    cin >> n >> m;
    for(int i = n; i <= m; i++)
    {
        int num = i;
        int count = 0;
        while(1)
        {
            count++;
            if(num % count == 0 && num == count * count)
            {
                sum += num;
                if(min > num)
                    min = num;
                break;
            }
            if(num <= count)
                break;
        }
    }
    if(sum == 0 && min == 10001)
    {
        cout << -1 << "\n";
        return 0;
    }
    cout << sum << "\n";
    cout << min << "\n";
}