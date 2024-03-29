#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class point{
    public:
        double x;
        double y;
};
bool check(point a, point b)
{
    if(a.x == b.x)
        return a.y < b.y;
    return a.x < b.x;
}
double ccw(point a, point b, point c)
{
    double result = a.x * b.y + b.x * c.y + c.x * a.y - a.y * b.x - b.y * c.x - c.y * a.x;
    if(result < 0)
        return -1;
    else if(result == 0)
        return 0;
    else
        return 1;    
}
int main(void)
{
    vector<point> L1(2, {0, 0});
    vector<point> L2(2, {0, 0});
    bool ans = false;
    cin >> L1[0].x >> L1[0].y >> L1[1].x >> L1[1].y;
    cin >> L2[0].x >> L2[0].y >> L2[1].x >> L2[1].y;
    int r1, r2, r3, r4;
    r1 = ccw(L1[0], L1[1], L2[0]);
    r2 = ccw(L1[0], L1[1], L2[1]);
    r3 = ccw(L2[0], L2[1], L1[0]);
    r4 = ccw(L2[0], L2[1], L1[1]);
    if(r1 == 0 && r2 == 0)
    {
        sort(L1.begin(), L1.end(), check);
        sort(L2.begin(), L2.end(), check);
        if(check(L1[0], L2[0]))
            ans = check(L1[1], L2[0]) ? false : true;
        else
            ans = check(L2[1], L1[0]) ? false : true;
    }
    else if(r1 * r2 <= 0)
    {
        if(r3 * r4 <= 0)
            ans = true;
    }
    cout << ans << "\n";
}