#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main(void)
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
    string input;
    cin >> input;
    int t;
    cin >> t;
    vector<vector<int>> memo(26, vector<int>(input.size() + 1, 0));
    for(int i = 1; i <= input.size(); i++)
    {
        memo[input[i - 1] - 'a'][i]++;
        for(int j = 0; j < 26; j++)
        {
            memo[j][i] += memo[j][i - 1];
        }
    }
    for(int i = 0; i < t; i++)
    {
        char check;
        int a, b;
        cin >> check >> a >> b;
        cout << memo[check -'a'][b + 1] - memo[check - 'a'][a] << "\n";
    }
}