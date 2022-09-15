#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int ccw(pair<long long int, long long int> a, pair<long long int, long long int> b, pair<long long int, long long int> c)
{
    long long ans = a.first * b.second + b.first * c.second + c.first * a.second - a.second * b.first - b.second * c.first - c.second * a.first;
    if(ans < 0)
        return -1;
    else if( ans == 0)
        return 0;
    else    
        return 1;
}
int main(void)
{
    pair<long long int, long long int> a, b;
    pair<long long int, long long int> c, d;
    long long int dist1, dist2, dist3, dist4;
    cin >> a.first >> a.second >> b.first >> b.second;
    cin >> c.first >> c.second >> d.first >> d.second;
    dist1 = ccw(a, b, c);
    dist2 = ccw(a, b, d);
    bool ans = false;
    if(dist1 * dist2 < 0)\
    {
        dist3 = ccw(c, d, a);
        dist4 = ccw(c, d, b);
        if(dist3 * dist4 < 0)
            ans = true;
    }
    cout << ans << "\n";
}