#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(void)
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n, m;
    int answer = 0;
    vector<int> num;
    cin >> n;
    cin >> m;
    for(int i = 0; i < n; i++)
    {
        int input;
        cin >> input;
        num.push_back(input);
    }
    sort(num.begin(), num.end());
    for(int i = 0; i < n; i++)
    {
        if(num[i] == 0)
            continue;
        int init = num[i];
        for(int j = num.size() - 1; j > i; j--)
        {
            if(num[j] == 0)
                continue;
            if(init + num[j] < m)
                break;
            else if(init + num[j] == m)
            {
                answer++;
                num[j] = 0;
                num[i] = 0;
                break;
            }
        }
    }
    cout << answer << "\n";
}