#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
class student
{
    public:
    int num;
    int count;
    int time;
};
bool comp(student a, student b)
{
    if(a.count == b.count)
        return a.time > b.time;
    return a.count > b.count;
}
int main(void)
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
    int n;
    int t;
    cin >> n;
    cin >> t;
    vector<student> photo;
    vector<int> num(105, 0);
    vector<int> ans; 
    for(int i = 0; i < t; i++)
    {
        int vote;
        cin >> vote;
        if(num[vote] != 0)
        {
            for(int j = 0; j < n; j++)
            {
                if(photo[j].num == vote)
                {
                    photo[j].count++;
                }
            }
        }
        else
        {
            if(photo.size() == n)
            {
                num[photo.back().num] = 0;
                photo.pop_back();
            }
            photo.push_back({vote, 1, i});
        }
        num[vote]++;
        sort(photo.begin(), photo.end(), comp);
        for(int j = 0; j < photo.size(); j++)
            cout << photo[j].num << " ";
        cout << endl;
    }
        for(int i = 0; i < photo.size(); i++)
        {
            ans.push_back(photo[i].num);
        }
        sort(ans.begin(), ans.end());
        for(int ans: ans)
            cout << ans << " ";
        cout << endl;
}