#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
bool solution(vector<string> p_book, int n)
{
    for(int i = 0; i < n; i++)
    {
        int size = p_book[i].size();
        for(int j = i + 1; j < n; j++)
        {
            bool answer = false;
            for(int k = 0; k < size; k++)
            {
                if(p_book[i][k] != p_book[j][k])
                {
                    answer = true;
                    break;
                }
            }   
            if(answer == false)
            {
                return false;
            }
        }
    }
    return true;
}
int main(void)
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    for(int i = 0; i < t; i++)
    {
        int n;
        cin >> n;
        vector<string> p_book(n, "");
        for(int j = 0; j < n; j++)
            cin >> p_book[j];
        sort(p_book.begin(), p_book.end());
        if(solution(p_book, n) == false)
            cout << "NO\n";
        else
            cout << "YES\n";
    }
}