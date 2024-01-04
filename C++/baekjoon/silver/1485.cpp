#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
class point{
    public:
    int x;
    int y;
};
bool comp(point a, point b)
{
    if(a.x == b.x)
        return a.y < b.y;
    return a.x < b.x;
}
int length(point a, point b)
{
    return (b.x - a.x) * (b.x - a.x) + (b.y - a.y) *(b.y - a.y);
}
int solution(vector<point> dots)
{
    sort(dots.begin(), dots.end(), comp);
    int diagonal = length(dots[0], dots[3]);
    int diagonal2 = length(dots[1], dots[2]);
    vector<int> dist(3, 0);
    dist[0] = length(dots[0], dots[1]);
    dist[1] = length(dots[0], dots[2]);
    dist[2] = length(dots[1], dots[3]);
    dist[3] = length(dots[2], dots[3]);
    if(dist[0] == dist[1] && dist[1] == dist[2] && dist[2] == dist[3] && diagonal == diagonal2)
        return 1;
    return 0;
}
int main(void)
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    for(int i = 0; i < t; i++)
    {
        vector<point> dots(4, {0, 0});
        for(int j = 0; j < 4; j++)
            cin >> dots[j].x >> dots[j].y;
        cout << solution(dots) << "\n";
    }
}