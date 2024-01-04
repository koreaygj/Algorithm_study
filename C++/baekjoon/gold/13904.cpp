#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
class task{
    public:
    int due;
    int score;
};
bool comp(task a, task b)
{
    if(a.score == b.score)
        return a.due < b.due;
    return a.score > b.score;
}
int main(void)
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<task> input(n, {0, 0});
    for(int i = 0; i < n; i++)
        cin >> input[i].due >> input[i].score;
    sort(input.begin(), input.end(), comp);
    vector<int> date(1005, 0);
    int answer = 0;
    for(int i = 0; i < n; i++)
    {
        if(date[input[i].due] == 0)
            date[input[i].due] = input[i].score;
        else
        {
            int count = input[i].due;
            while(count >= 1)
            {
                count--;
                if(date[count] == 0)
                {
                date[count] = input[i].score;
                break;
                }
            }

        }
    }
    for(int i = 1; i <= 1000; i++)
        answer += date[i];
    cout << answer << "\n";
}