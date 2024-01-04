#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main(void)
{
    int n;
    long long int answer = 0;
    cin >> n;
    vector<int> rope(n, 0);
    for(int i = 0; i < n; i++)
        cin >> rope[i];
    sort(rope.begin(), rope.end());
    for(int i = 0; i < n; i++)
    {
        long long int max = rope[i] * (n - i);
        if(answer < max)
            answer = max;
    }
    cout << answer << "\n";
}