#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
using namespace std;
int answer;
vector<int> ans(8, 0);
vector<int> memo(8, 0);
int ccw(int init)
{
    double a = ans[init];
    double b = ans[(init + 1) % 8];
    double c = ans[(init + 2) % 8];
    if(b * (a + c) < (a * c * sqrt(2)))
        return 1;
    return 0;
}
bool check()
{
    for(int i = 0; i < 8; i++)
    {
        if(ccw(i) != 0)
            return false;
    }
    return true;
}
void dfs(vector<int> array, int count)
{
    if(count == 8)
    {
        if(check())
            answer++;
        return;
    }
    for(int i = 0; i < 8; i++)
    {
        if(memo[i] != 0)
            continue;
        memo[i] = 1;
        ans[count] = array[i];
        dfs(array, count + 1);
        memo[i] = 0;
    }
}
int main(void)
{
    vector<int> array(8, 0);
    for(int i = 0; i < 8; i++)
        cin >> array[i];
    dfs(array, 0);
    cout << answer << "\n";
}