#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
class point{
    public:
    double x;
    double y;
};
double solution(vector<point> dots, int num)
{
    int st = num - 1;
    double result = 0;
    for(int i = 0; i < num; i++)
    {
        result += dots[st].x * dots[i].y - dots[st].y * dots[i].x;
        st = i;
    }
    result = result < 0 ? -result : result;
    result /= 2;
    return result;
}
int main(void)
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<point> dots(n, {0, 0});
    for(int i = 0; i < n; i++)
        cin >> dots[i].x >> dots[i].y;
    double answer = solution(dots, n);
    cout << fixed;
    cout.precision(1);
    cout << ceil(answer * 10) / 10 << "\n";
}