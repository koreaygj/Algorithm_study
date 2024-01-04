#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
int main(void)
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<int> neg(10000005, 0);
    vector<int> pos(10000005, 0);
    for(int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        if(num < 0)
            neg[num * -1] = 1;
        else
            pos[num] = 1;
    }
    int m;
    cin >> m;
    for(int i = 0; i < m ;i++)
    {
        int check_num;
        cin >> check_num;
        if(check_num < 0)
        {
            if(neg[check_num * -1] != 0)
                cout << "1 ";
            else
                cout << "0 ";
        }
        else
        {
            if(pos[check_num] != 0)
                cout << "1 ";
            else
                cout << "0 ";
        }
    }
}