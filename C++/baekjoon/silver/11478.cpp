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
    string input;
    cin >> input;
    map<string, bool> set;
    for(int i = 0; i < input.size(); i++)
    {
        string subset = "";
        for(int j = i; j < input.size(); j++)
        {
            subset += input[j];
            set[subset] = false;
        }
    }
    cout << set.size() << "\n";
}