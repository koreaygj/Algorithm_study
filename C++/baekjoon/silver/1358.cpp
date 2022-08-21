#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int w, h, x, y, p;
int area1(int a, int b)
{
    int c_x, c_y;
    c_x = x;
    c_y = y + (h / 2);
    if(((c_x - a) * (c_x - a) + (c_y - b) * (c_y - b)) <= (h / 2) * (h / 2))
        return 1;
    return 0;
}
int area2(int a, int b)
{
    if(b >= y && b <= y + h)
        return 1;
    return 0;
}
int area3(int a, int b)
{
    int c_x, c_y;
    c_x = x + w;
    c_y = y + h / 2;
    if((c_x - a) * (c_x - a) + (c_y - b) * (c_y - b) <= (h / 2) * (h / 2))
        return 1;
    return 0;
}
int main(void)
{
    cin >> w >> h >> x >> y >> p;
    int ans = 0;
    for(int i = 0; i < p; i++)
    {
        int a, b;
        cin >> a >> b;
        if(a < x)
            ans += area1(a, b);
        else if(x <= a && a <= (x + w))
            ans += area2(a, b);
        else
            ans += area3(a, b);
    }
    cout << ans << "\n";
}