#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
class length
{
    public:
        int s_t;
        int f_t;
};
bool comp(length a, length b)
{
    if(a.s_t == b.s_t)
        return a.f_t < b.f_t;
    return a.s_t < b.s_t;
}
int main(void)
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<length> lacture(n , {0, 0});
    for(int i = 0; i < n; i++)
        cin >> lacture[i].s_t >> lacture[i].f_t;
    sort(lacture.begin(), lacture.end(), comp);
    priority_queue<int, vector<int>, greater<int>> room;
    room.push(lacture[0].f_t);
    for(int i = 1; i < n; i++)
    {
        int current = room.top();
        if(current > lacture[i].s_t)
            room.push(lacture[i].f_t);
        else
        {
            room.pop();
            room.push(lacture[i].f_t);
        }
    }
    cout << room.size() << "\n";
}