#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
int main(void)
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    map<string, int> pokemon;
    vector<string> arr(n + 1, "");
    for(int i = 1; i <= n; i++)
    {
        string input;
        cin >> input;
        pokemon[input] = i;
        arr[i] = input;
    }
    for(int i = 0; i < m; i++)
    {
        string input;
        cin >> input;
        if( 'A' <= input[0] && input[0] <= 'Z')
            cout << pokemon[input] << "\n";
        else if('a' <= input[0] && input[0] <= 'z')
            cout << pokemon[input] << "\n";
        else
            cout << arr[stoi(input)] << "\n";
    }
}