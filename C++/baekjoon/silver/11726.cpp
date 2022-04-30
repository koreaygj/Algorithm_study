#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int solution(int n)
{
    vector<int> squre(10001, 1);
    squre[0] = 0;
    squre[1] = 1;
    squre[2] = 2;
    for(int i = 2; i <= n+1; i++)
    {
        squre[i] = squre[i-1] % 10007  + squre[i-2] % 10007;
    }
    return squre[n+1] % 10007;
}
int main(void)
{
    int n;
    cin >> n;
    cout << solution(n) << "\n";
}