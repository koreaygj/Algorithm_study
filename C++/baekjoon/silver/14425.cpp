#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
bool comp(string a, string b)
{
    return a.size() < b.size();
}
int main(void)
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
    int n, m;
    int answer = 0;
    cin >> n >> m;
    map<string, bool> s;
    for(int i = 0; i < n; i++)
    {
        string input;
        cin >> input;
        s[input] = true;
    }
    for(int i = 0; i < m; i++)
    {
        string input;
        cin >> input;
        if(s[input] != true)
            continue;
        answer++;
    }
    cout << answer <<"\n";
}