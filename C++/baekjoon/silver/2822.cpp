#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
class problem{
    public:
        int num;
        int score;
};
bool comp(problem a, problem b)
{
    return a.score > b.score;
}
bool comp2(problem a, problem b)
{
    return a.num < b.num;
}
int main(void)
{
    vector<problem> arr(8, {0, 0});
    int sum = 0;
    for(int i = 0; i < 8; i++)
    {
        int input;
        cin >> input;
        arr.push_back({i + 1, input});
    }
    sort(arr.begin(), arr.end(), comp);
    sort(arr.begin(), arr.begin() + 5, comp2);
    for(int i = 0; i < 5; i++)
        sum += arr[i].score;
    cout << sum << "\n";
    for(int i = 0; i < 5; i++)
        cout << arr[i].num << " ";
}