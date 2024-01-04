#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
class point{
    public:
    int x;
    int y;
};
double calculate(point a, point b)
{
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    int answer = 0;
    double m = 9876543210;
    cin >> n;
    vector<point> shelter(n, {0, 0});
    for(int i = 0; i < n; i++)
        cin >> shelter[i].x >> shelter[i].y;
    for(int i = 0; i < n; i++)
    {
        double distance = 0;
        for(int j = 0; j < n; j++)
        {
            if(i == j)
                continue;
            double cur = calculate(shelter[i], shelter[j]);
            distance = max(cur, distance);
        }
        if(distance < m)
        {
            m = distance;
            answer = i;
        }
    }
    cout << shelter[answer].x << " " << shelter[answer].y << "\n";
}