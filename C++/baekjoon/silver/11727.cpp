#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int solution(int n)
{
    vector<int> rect(1001, 0);
    rect[0] = 1;
    rect[1] = 3;
    for(int i = 2; i < n; i++)
    {
        rect[i] = rect[i-1] % 10007 + rect[i-2] * 2 %10007;
    }
    return rect[n-1] %10007;
}
int main(void)
{
    int n;
    cin >> n;
    cout << solution(n) << "\n";
}