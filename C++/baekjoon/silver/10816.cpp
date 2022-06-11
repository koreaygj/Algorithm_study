#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
int main(void)
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
    int n, m;
    cin >> n;
    map<int, int> num_card;
    for(int i = 0; i < n; i++)
    {
        int input;
        cin >> input;
        num_card[input]++;
    }
    cin >> m;
    for(int i = 0; i < m; i++)
    {
        int result;
        cin >> result;
        cout << num_card[result] << " ";
    }
}