#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main(void)
{
    vector<int> w(10, 0);
    vector<int> k(10, 0);
    for(int i = 0; i < 10 ; i++)
        cin >> w[i];
    for(int i = 0; i < 10 ; i++)
        cin >> k[i];
    sort(w.begin(), w.end());
    sort(k.begin(), k.end());
    cout << w[9] + w[8] + w[7] << " " << k[9] + k[8] + k[7];
}