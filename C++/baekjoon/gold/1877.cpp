#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<pair<int, int>> A_ans;
vector<pair<int, int>> B_ans;
int problem_A(int m, vector<int> arr, int count)
{
    if(m == 0)
    {
        int mul = 1;
        for(int i = 0; i < arr.size(); i++)
            mul *= arr[i];
        A_ans.push_back({mul, count});
        return 0;
    }
    for(int i = arr.back(); i <= m; i++)
    {
        if(m - i < 0)
            return 0;
        arr.push_back(i);
        problem_A(m - i, arr, count + 1);
        if(!arr.empty())
            arr.pop_back();
    }
    return 0;
}
int problem_B(int m, vector<int> arr, int count)
{
    if(m == 1)
    {
        int sum = 0;
        for(int i = 0; i < arr.size(); i++)
            sum += arr[i];
        B_ans.push_back({sum, count});
        return 0;
    }
    for(int i = arr.back(); i <= m; i++)
    {
        if(m / i < 1)
            return 0;
        if(m % i != 0)
            continue;
        arr.push_back(i);
        problem_B(m / i, arr, count + 1);
        if(!arr.empty())
            arr.pop_back();
    }
    return 0;
}
int main(void)
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
    int m;
    cin >> m;
    for(int i = 1; i <= m; i++)
    {
        vector<int> arr;
        arr.push_back(i);
        problem_A(m - i, arr, 1);
        if(!arr.empty())
            arr.pop_back();
    }
    for(int i = 2; i * i <= m; i++)
    {
        vector<int> arr;
        if(m % i != 0)
            continue;
        arr.push_back(i);
        problem_B(m / i, arr, 1);
        if(!arr.empty())
            arr.pop_back();
    }
    sort(A_ans.begin(), A_ans.end());
    sort(B_ans.begin(), B_ans.end());
    int index1, index2;
    for(int i = A_ans.size() - 1; i >= 0; i--)
    {
        if(A_ans.back().first != A_ans[i].first)
        {
            index1 = i;
            break;
        }
    }
    for(int i = B_ans.size() - 1; i >= 0; i--)
    {
        if(B_ans.back().first != B_ans[i].first)
        {
            index2 = i;
            break;
        }
    }
    if(A_ans.size() == 1)
        index1 = -1;
    if(B_ans.size() == 1)
        index2 = -1;
    cout << A_ans.back().second << " " << A_ans[index1 + 1].second << " "  << B_ans.back().second << " " << B_ans[index2 + 1].second << "\n";
}