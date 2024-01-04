#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int ccw(vector<pair<int, int>> p)
{
    return (p[1].first - p[0].first) * (p[2].second - p[0].second) - (p[1].second -p[0].second) * (p[2].first - p[0].first);
}
int main(void){
    vector<pair<int, int>> p(3, {0, 0});
    for(int i = 0; i < 3; i++)
        cin >> p[i].first >> p[i].second;
    if(ccw(p) >0)
        cout << "1\n";
    else if(ccw(p) == 0)
        cout << "0\n";
    else
        cout << "-1\n";
    return 0;
}