#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
int main(void)
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
    int n, m;
    int answer = 0;
    cin >> n >> m;
    map<string, bool> name;
    for(int i = 0; i < n; i++)
    {
        string input;
        cin >> input;
        name[input] = true;
    }
    for(int i = 0; i < m; i++)
    {
        string result;
        cin >> result;
        if(name.find(result) != name.end())
        {
            name[result] = false;
            answer++;
        }
    }
    cout << answer << "\n";
    for(auto& it: name)
    {
        if(it.second == false)
            cout << it.first << "\n";
    }
}