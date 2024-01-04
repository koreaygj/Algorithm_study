#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
bool check(int x, int y, int a, int b, int r)
{
    if(pow(abs(x - a), 2) + pow(abs(y - b), 2) < r * r)
        return true;
    return false;    
}
int main(void)
{
    int k;
    cin >> k;
    for(int i = 0; i < k; i++)
    {
        int answer = 0;
        int init_x, init_y, dist_x, dist_y;
        cin >> init_x >> init_y >> dist_x >> dist_y;
        int n; 
        cin >> n;
        for(int j = 0; j < n; j++)
        {
            int a, b, r;
            cin >> a >> b >> r;
            if(check(init_x, init_y, a, b, r) && !check(dist_x, dist_y, a, b, r))
                answer++;
            if(check(dist_x, dist_y, a, b, r) && !check(init_x, init_y, a, b, r))
                answer++;
        }
        cout << answer << endl;
    }
}