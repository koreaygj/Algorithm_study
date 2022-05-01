#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(void)
{
    int n;
    cin >> n;
    vector<int> p(1001, 0);
    for(int i = 1; i <= n; i++)
        cin >> p[i];
    for(int i = 2; i <= n ; i++)
    {
        for(int j = 1; j <= i/2; j++)
            p[i] = max(p[i] , p[i-j] + p[j]);
    }
    cout << p[n] << "\n";
}