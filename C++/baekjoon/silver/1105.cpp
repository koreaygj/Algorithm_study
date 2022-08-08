#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main(void)
{
    string l, r;
    cin >> l >> r;
    int ans = 0;
    if(l.size() == r.size())
    {
        for(int i = 0; i < l.size(); i++)
        {
            if(l[i] == '8' && r[i] == '8')
                ans++;
            else if(l[i] != r[i])
                break;
        }
    }
    cout << ans << "\n";
}